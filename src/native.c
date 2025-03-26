#include "native.h"

#include <time.h>

static runtimeErrorFn runtimeError;

static Value clockNative(int argCount, Value *args, bool *success)
{
    if (argCount != 0)
    {
        runtimeError("Expected 0 arguments but got %d.", argCount);
        *success = false;
        return NUMBER_VAL(0);
    }
    *success = true;
    return NUMBER_VAL((double)clock() / CLOCKS_PER_SEC);
}

void defineAllNatives(defineNativeFn defineNative, runtimeErrorFn rError)
{
    runtimeError = rError;
    defineNative("clock", clockNative);
}