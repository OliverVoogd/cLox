#include "common.h"
#include "chunk.h"
#include "debug.h"

// Can we write a makefile for this and
// compile and run the whole project on WSL?
int main(int argc, const char *argv[])
{
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}