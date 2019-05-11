#ifndef LCC_TOKEN_UNDEFINED
#define LCC_TOKEN_UNDEFINED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lcc_input_gather.c"

struct lcc_tk_undefined {
    char c;
};

#include "lcc_token.c" 

int lcc_tk_undefined__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    char c;
    if (lcc_input__getc(f, &c) == ERROR) {
        return ERROR;
        printf("ERRO!!!");
    }
    tk->undefined = malloc(sizeof(struct lcc_tk_undefined));
    tk->undefined->c = c;
    tk->type = UNDEFINED;
    return SUCESS;
}

#endif
