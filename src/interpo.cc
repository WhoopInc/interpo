#include <node.h>

#include "pchip_interpolator.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("Pchip"), PchipInterpolator::Init());
}

NODE_MODULE(interpo, InitAll);
