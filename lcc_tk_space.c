#ifndef LCC_TOKEN_SPACE
#define LCC_TOKEN_SPACE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

struct lcc_tk_space {
};


int lcc_tk_space__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->type = SPACE;
    char c;
    lcc_input__getc(f, &c); // just to skip the char
    return SUCESS;
}

#endif

