#include <node.h>
#include <nan.h>

#include "pchip_interpolator.h"
#include "slatec/slatec.h"

using namespace v8;

static Persistent<Function> constructor;

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

Handle<Function> PchipInterpolator::Init() {
  // Turn off SLATEC's diagnostic output for recoverable errors.
  int kontrl = 0;
  xsetf_(kontrl);

  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->SetClassName(NanNew<String>("PchipInterpolator"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  NODE_SET_PROTOTYPE_METHOD(tpl, "evaluate", Evaluate);

  NanAssignPersistent(constructor, tpl->GetFunction());
  return constructor;
}

NAN_METHOD(PchipInterpolator::New) {
  NanEscapableScope();

  if (!args.IsConstructCall()) {
    const int argc = 2;
    Local<Value> argv[argc] = { args[0], args[1] };
    NanReturnValue(constructor->NewInstance(argc, argv));
  }

  if (!args[0]->IsArray() || !args[1]->IsArray()) {
    return NanThrowTypeError("expected two array args");
  }

  Local<Array> x = Local<Array>::Cast(args[0]);
  Local<Array> f = Local<Array>::Cast(args[1]);

  if (x->Length() != f->Length()) {
    return NanThrowTypeError("array lengths must match");
  }

  if (!IsNumericArray(x) || !IsNumericArray(f)) {
    return NanThrowTypeError("array contains non-numeric elements");
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
    case -1: return NanThrowError("less than two data points");
    case -3: return NanThrowError("x array not strictly increasing");
    default: return NanThrowError("internal error", ierr);
  }

  obj->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(PchipInterpolator::Evaluate) {
  NanEscapableScope();

  if (!args[0]->IsNumber()) {
    NanThrowError("expecting one numeric arg");
  }

  PchipInterpolator *obj = ObjectWrap::Unwrap<PchipInterpolator>(args.This());

  int ierr = 0;
  int incfd = 1;
  int skip = 1;

  int ne = 1;
  double xe = args[0]->NumberValue();
  double fe;

  dpchfe_(obj->n, obj->x, obj->f, obj->d, incfd, skip, ne, xe, fe, ierr);

  switch (ierr) {
    case 0: break;
    case 1: return NanThrowError("x out of range");
    default: return NanThrowError("internal error", ierr);
  }

  NanReturnValue(NanNew<Number>(fe));
}
