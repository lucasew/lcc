#ifndef LCC_TOKEN_SEMICOLON
#define LCC_TOKEN_SEMICOLON
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

int lcc_tk_semicolon__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->type = SEMICOLON;
    char c;
    lcc_input__getc(f, &c); // just to skip the char
    return SUCESS;
}

#endif

