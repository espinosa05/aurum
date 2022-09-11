/*
MIT License

Copyright (c) 2022 Francisco Fischer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "aurum.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

#include "aurum_parser.h"

#define BUFFER_SIZE (1024 * 1024)


int create_file_buffer(char *buffer, int fd)
{
    int fileSize;
    int lineCount = 0;
    char *fileBuffer;

    fileSize = read(fd, fileBuffer, BUFFER_SIZE);

    if (fileSize == BUFFER_SIZE) {
        printf("buffer is probably too big\n");
        exit(EXIT_FAILURE);
    }

    fileBuffer[fileSize] = '\0';
    strcpy(buffer, fileBuffer);
    return fileSize;
}

int get_lines_from_buffer(char *fileBuffer)
{
    int currentByte = 0;
    int lineCount = 0;
    while(fileBuffer[currentByte] !=  0) {
        if (fileBuffer[currentByte] == '\n') {
            lineCount++;
        }
    }
#ifdef _DEBUG
    printf("lines:\t%d\nsize:\t%d\nbuffer:\n\n%s\n", lineCount, currentByte,
           fileBuffer);
#endif // _DEBUG

    return lineCount;
}


void get_cli_argument(char *argv) { return; } // stub

__attribute__((always_inline)) void program_prologue(char *programName, char *fileBuffer)
{
    sprintf(fileBuffer, "; file: %s.asm\n\nsection .text\n\n"
                        "global _start:\n\n", programName);
}

__attribute__((always_inline)) void init_subroutine(char *symbol, char *fileBuffer, int offset)
{
    sprintf(&fileBuffer[offset],
            "section .text\n"
            "global %s\n"
            "%s:\n\n"
            "\tpush ebp\n"
            "\tmov ebp, esp\n"
            , symbol, symbol);
}

__attribute__((always_inline)) void function_cleanup(char *fileBuffer, int offset)
{ sprintf(&fileBuffer[offset],"\tpop ebp\n\tret\n\n"); }

__attribute__((always_inline)) program_epilogue(char *fileBuffer, int offset)
{
    sprintf(&fileBuffer[offset], "mov ebx, eax\n"
                                 "\tmov eax, 1\n"
                                 "\tint 0x80");
}

