#include "native.h"

#include <time.h>
#include <stdlib.h>

#include "value.h"

static runtimeErrorFn runtimeError;

static Value clockNative(int argCount, Value *args, bool *success)
{
    if (argCount != 0)
    {
        runtimeError("Expected 0 arguments but got %d.", argCount);
        *success = false;
        return NIL_VAL;
    }
    *success = true;
    return NUMBER_VAL((double)clock() / CLOCKS_PER_SEC);
}

static Value absNative(int argCount, Value *args, bool *success)
{
    if (argCount != 1)
    {
        runtimeError("Expected 1 argument but got &d.", argCount);
        *success = false;
        return NIL_VAL;
    }
    if (!IS_NUMBER(args[0]))
    {
        runtimeError("Expected a number to 'abs' native function.");
        *success = false;
        return NIL_VAL;
    }
    *success = true;
    return NUMBER_VAL(abs(AS_NUMBER(args[0])));
}

void defineAllNatives(defineNativeFn defineNative, runtimeErrorFn rError)
{
    runtimeError = rError;
    defineNative("clock", clockNative);
    defineNative("abs", absNative);
}