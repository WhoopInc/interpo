#ifndef PCHIP_INTERPOLATOR_H
#define PCHIP_INTERPOLATOR_H

#include <nan.h>
#include <node.h>

class PchipInterpolator : public node::ObjectWrap {
  public:
    static v8::Handle<v8::Function> Init();
    static NAN_METHOD(NewInstance);

  private:
    PchipInterpolator();
    ~PchipInterpolator();

    static NAN_METHOD(New);
    static NAN_METHOD(Evaluate);

    int n;
    double *x;
    double *f;
    double *d;
};

#endif
