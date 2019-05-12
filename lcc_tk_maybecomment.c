#ifndef LCC_TOKEN_MAYBECOMMENT
#define LCC_TOKEN_MAYBECOMMENT

#include "lcc_token.c"
#include "lcc_input_gather.c"
#include "lcc_status.h"
#include "lcc_token_parser.c"

int lcc_tk_maybecomment__parse(struct lcc_input_wrapper *input, struct lcc_token *tk) {
    // Only called if first is /
    char c;
    int loop = 1;
    char last;
    lcc_input__getc(input, &c); // first is the / itself
    lcc_input__getc(input, &c);
    switch (c) {
    case '/':
        while(c != '\n')
            lcc_input__getc(input, &c);break;
    case '*':
        while(loop) {
            last = c;
            lcc_input__getc(input, &c);
            if (last == '*' && c == '/')
                break;
        };break;
    default: 
        tk->type = DIV;
        lcc_input__ungetc(input, c);
        return SUCESS;
    }
    tk->type = INVALID;
    return SUCESS;
}

#endif
