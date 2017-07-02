#include <node.h>
#include <nan.h>

#include "pchip_interpolator.h"
#include "slatec.h"

using namespace v8;

static Nan::Persistent<Function> constructor;

bool IsNumericArray(Local<Array> arr) {
  int length = arr->Length();
  for (int i = 0; i < length; i++) {
    if (!arr->Get(i)->IsNumber()) {
      return false;
    }
  }
  return true;
}

PchipInterpolator::PchipInterpolator() {};
PchipInterpolator::~PchipInterpolator() {};

Nan::Persistent<Function>& PchipInterpolator::Init() {
  // Turn off SLATEC's diagnostic output for recoverable errors.
  int kontrl = 0;
  xsetf_(kontrl);

  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);

  tpl->SetClassName(Nan::New<String>("PchipInterpolator").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "evaluate", Evaluate);

  constructor.Reset(tpl->GetFunction());
  return constructor;
}

NAN_METHOD(PchipInterpolator::New) {
  Nan::EscapableHandleScope scope;

  if (!info.IsConstructCall()) {
    const int argc = 2;
    Local<Value> argv[argc] = { info[0], info[1] };
    info.GetReturnValue().Set(
      Nan::NewInstance(Nan::New(constructor), argc, argv).ToLocalChecked());
    return;
  }

  if (!info[0]->IsArray() || !info[1]->IsArray()) {
    return Nan::ThrowTypeError("expected two array args");
  }

  Local<Array> x = Local<Array>::Cast(info[0]);
  Local<Array> f = Local<Array>::Cast(info[1]);

  if (x->Length() != f->Length()) {
    return Nan::ThrowTypeError("array lengths must match");
  }

  if (!IsNumericArray(x) || !IsNumericArray(f)) {
    return Nan::ThrowTypeError("array contains non-numeric elements");
  }

  PchipInterpolator *obj = new PchipInterpolator();

  obj->n = x->Length();
  obj->x = new double[obj->n];
  obj->f = new double[obj->n];
  obj->d = new double[obj->n];

  for (int i = 0; i < obj->n; i++) {
    obj->x[i] = x->Get(i)->NumberValue();
    obj->f[i] = f->Get(i)->NumberValue();
  }

  int ierr;
  int incfd = 1;
  dpchim_(obj->n, obj->x, obj->f, obj->d, incfd, ierr);

  switch (ierr) {
    case 0: break;
    case -1: return Nan::ThrowError("less than two data points");
    case -3: return Nan::ThrowError("x array not strictly increasing");
    default: return Nan::ThrowError("internal error");
  }

  obj->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(PchipInterpolator::Evaluate) {
  Nan::EscapableHandleScope scope;

  if (!info[0]->IsNumber()) {
    Nan::ThrowError("expecting one numeric arg");
  }

  PchipInterpolator *obj = Nan::ObjectWrap::Unwrap<PchipInterpolator>(info.This());

  int ierr = 0;
  int incfd = 1;
  int skip = 1;

  int ne = 1;
  double xe = info[0]->NumberValue();
  double fe;

  dpchfe_(obj->n, obj->x, obj->f, obj->d, incfd, skip, ne, xe, fe, ierr);

  switch (ierr) {
    case 0: break;
    case 1: return Nan::ThrowError("x out of range");
    default: return Nan::ThrowError("internal error");
  }

  info.GetReturnValue().Set(Nan::New<Number>(fe));
}
