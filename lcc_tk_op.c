#ifndef LCC_TOKEN_OP
#define LCC_TOKEN_OP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

enum lcc_op_type {
    SUM,
    SUB,
    MUL,
    DIV,
    ATTRIB,
    PIPE
};

struct lcc_tk_op {
    enum lcc_op_type type;
};

#define LCC_OP_RULE(ch, value) \
    if (c == ch) { \
        tk->op->type = value; \
    }

int lcc_tk_op__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->op = malloc(sizeof(struct lcc_tk_op));
    tk->type = OP;
    char c;
    lcc_input__getc(f, &c);
    LCC_OP_RULE('+', SUM);
    LCC_OP_RULE('-', SUB);
    LCC_OP_RULE('*', MUL);
    LCC_OP_RULE('/', DIV);
    LCC_OP_RULE('=', ATTRIB);
    LCC_OP_RULE('|', PIPE);
    /* printf(tk->number->num); */
    return SUCESS;
}

#endif

