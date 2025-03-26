
#include "object.h"

typedef void (*defineNativeFn)(const char *name, NativeFn function);
typedef void (*runtimeErrorFn)(const char *format, ...);

void defineAllNatives(defineNativeFn, runtimeErrorFn);