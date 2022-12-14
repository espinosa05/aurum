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

#ifndef AURUM_AURUM_H
#define AURUM_AURUM_H

#include <stdbool.h>
#include <stdint.h>


#define AURUM_VERSION_MINOR 1
#define AURUM_VERSION_MAJOR 0

/* the parser uses this to generate the code based on conditions */


struct aurum_options {
    bool assemble;
    bool 
};


int get_lines_from_buffer(char *fileBuffer);

void get_cli_argument(char *argv);

int create_file_buffer(char *buffer, int fd);

void parser(struct program_tree *programTree);

void program_prologue(char *programName, char *fileBuffer);

void init_subroutine(char *symbol, char *fileBuffer, int offset);

void function_cleanup(char *fileBuffer, int offset);

#endif /* AURUM_AURUM_H */

