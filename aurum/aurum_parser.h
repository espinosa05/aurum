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

#ifndef AURUM_PARSER_H
#define AURUM_PARSER_H

#include <stdlib.h>
#include <stdbool.h>
#define NUMBER_OF_TYPE_TOKENS 24

enum type_tokens {
    STORE, /* Storing in memory */
    LOAD,  /* load from memory */
    SET,   
    FUNCTION,
    DEFINITION,
    FUNCTION_CALL,
    DATA,
    MACRO,
    VARIABLE,
    VALUE,
    EXPRESSION,
    MATH,
    ADD,
    SUB,
    MUL,
    DIV,
    IF,
    ELSE,
    LOOP,
    FOR,
    WHILE,
    DO,
    SWITCH,
    ASM
};

// operation types

enum current_scope {
    GLOBAL,
    LOCAL
}
enum operations {
    PUSH,   // passing arguments
    CALL,   // function call
    INIT,   // function prologue
    FINI
};

struct symbol_table_entry {
    void *data;
    char *symbol;
};

struct outline_node {
   // int nodeCount;
    //uint8_t operation_type;
    struct symbol_table_entry *tableEntry;
    int leafCount;
    struct outline_node **leaf;
};



bool generate_tree(char *fileBuffer);
//static void init_n_ary_tree(struct outline_node *outlineNode, int nodeCount);
//static void dealloc_n_ary_tree(struct outline_node *outlineNode);
static void generate_outline(struct outline_node *outlineNode);
bool is_end_node(struct outline_node *outlineNode);
static void
//void set_nodes(struct outline_node *outlineNode, int numOfNodes, ...);
struct outline_node *generate_outline_node();


#endif //AURUM_PARSER_H
