#ifndef clox_compiler_h
#define clox_compiler_H

#include "vm.h"

ObjFunction *compile(const char *source);

#endif