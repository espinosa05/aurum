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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "aurum.h"

#define DEBUG_LOG(FMT, __VA_ARGS__) \
    #ifdef _DEBUG                   \
        printf(FMT, __VA_ARGS__);   \
    #endif /* _DEBUG */


int main(int argc, char **argv)
{

    if (argc < 2) {
        puts("error:\tinvalid number of arguments\nhave:\taurum\t<options> "
               "<files>\n");
        puts("for more information parse the -h option!\n");
        exit(-EINVAL);
    }
    
    int *sourceFiles;
    int outputFile;
    char *outputFileName;
    char *objectFileName;
    int intermediateFile; /* assembler file */
    int sourceFileCount;
    char **command = 0;
#ifdef _DEBUG
    int *lineCount;
#endif /* _DEBUG */
    int *sourceFileSizes;
    char **fileBuffers;
    struct aurum_options aurumOptions;
    
    sourceFiles = (int *)malloc(sizeof(int)); /* initial source file */
    for (int argCount = 1; argCount <= argc - 1; argCount++) {
        if (argv[argCount][0] == '-') {
            switch (argv[argCount][1]) {
                case 'S' : 
                    aurumOptions.assemble = false; 
                    DEGUG_LOG("assemble = false\n");
                    argCount++;
                    break;
                default :
                    printf("incopatible flag '-%c'", argv[argCount][1]);
                    free(sourceFiles);
                    exit(-EINVAL);
            }
        }
        sourceFiles = realloc(sourceFiles, sourceFileCount);
        sourceFiles[sourceFileCount] = open(argv[argCount], O_RDONLY);
        sourceFileCount++;
    }

#ifdef _DEBUG
    lineCount = malloc(sizeof(int) * sourceFileCount);
#endif /* _DEBUG */
    sourceFileSizes = malloc(sizeof(int) * sourceFileCount);
    
    for (int i = 0; i <= sourceFileCount - 1; i++) {
        fileSizes[i] = create_file_buffer(fileBuffers[i], sourceFiles[i]);
        lineCount[i] = get_lines_from_buffer(fileBuffers[i]);
    }

    /* parse the source files */
    for (int i = 0; i <= sourceFileCount; i++) {
        for (int j = 0; j <= fileSizes[i]; j++) {
            

        }
    }

#ifndef _DEBUG
    free(lineCount);
#endif /* _DEBUG */
    free(fileSizes);
   
    sprintf(command[0],"nasm -felf32 %s -o %s", sourceFiles, objectFileName);
    sprintf(command[1],"ld -melf_i386 -o %s", outputFileName);
    
    if(aurumOptions.assemble) {
        system(command[0]);
        system(command[1]);   
    }

    

    return 0;
}
