#ifndef LCC_TOKEN_BLOCK
#define LCC_TOKEN_BLOCK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

enum lcc_tk_block_openess {
    OPEN,
    CLOSE
};

enum lcc_tk_block_type {
    PARENTHESIS,    // ()
    ANGULAR,        // <>
    SQUARE,         // []
    CURLY           // {}
};


struct lcc_tk_block {
    enum lcc_tk_block_openess   openess;
    enum lcc_tk_block_type      type;
};

#define LCC_TK_BLOCK_OPTION(chr, oness, tp) \
    case chr: tk->block->openess = oness; tk->block->type = tp;break;


int lcc_tk_block__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->type = BLOCK;
    char c;
    lcc_input__getc(f, &c);
    tk->block = malloc(sizeof(struct lcc_tk_block));
    switch(c) {
        LCC_TK_BLOCK_OPTION('(', OPEN, PARENTHESIS);
        LCC_TK_BLOCK_OPTION('<', OPEN, ANGULAR);
        LCC_TK_BLOCK_OPTION('[', OPEN, SQUARE);
        LCC_TK_BLOCK_OPTION('{', OPEN, CURLY);
        LCC_TK_BLOCK_OPTION(')', CLOSE, PARENTHESIS);
        LCC_TK_BLOCK_OPTION('>', CLOSE, ANGULAR);
        LCC_TK_BLOCK_OPTION(']', CLOSE, SQUARE);
        LCC_TK_BLOCK_OPTION('}', CLOSE, CURLY);
        default: return ERROR;
    }
    return SUCESS;
}

#endif

