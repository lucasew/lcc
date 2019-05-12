#ifndef LCC_TOKEN_STRING_LITERAL
#define LCC_TOKEN_STRING_LITERAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"


static inline int 
_parse_str_literal(struct lcc_input_wrapper *f, struct lcc_tk_str *tk, int i) {
    char c;
    lcc_input__getc(f, &c);
    if (c != ('\'')) {
        int res = _parse_str_literal(f, tk, i + 1);
        tk->str[i] = c;
        return res;
    }
    tk->str = malloc(sizeof(char)*(i + 2));
    if (tk->str == NULL)
        return ERROR;
    tk->str[i] = '\0';
    return SUCESS;
}

int lcc_tk_str_literal__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->str = malloc(sizeof(struct lcc_tk_str));
    if (tk->str == NULL)
        return ERROR;
    char unget;
    lcc_input__getc(f, &unget); // Excludes the first "
    int ret = _parse_str_literal(f, tk->str, 0);
    if (ret == ERROR)
        return ERROR;
    /* printf("%i\n", strlen(tk->number->num)); */
    unget = tk->str->str[strlen(tk->str->str)];
    lcc_input__ungetc(f, unget);
    /* printf(tk->number->num); */
    return ret;
}

#endif

