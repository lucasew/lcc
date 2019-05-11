#ifndef LCC_TOKEN_SYMBOL
#define LCC_TOKEN_SYMBOL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

struct lcc_tk_symbol {
    char *str;
};


static inline int 
_parse_sym(struct lcc_input_wrapper *f, struct lcc_tk_symbol *tk, int i) {
    char c;
    lcc_input__getc(f, &c);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9')) {
        int res = _parse_sym(f, tk, i + 1);
        tk->str[i] = c;
        return res;
    }
    tk->str = malloc(sizeof(char)*(i + 2));
    if (tk->str == NULL)
        return ERROR;
    lcc_input__ungetc(f, c);
    tk->str[i] = '\0';
    return SUCESS;
}

int lcc_tk_sym__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->symbol = malloc(sizeof(struct lcc_tk_symbol));
    if (tk->str == NULL)
        return ERROR;
    char unget;
    tk->type = SYMBOL;
    int ret = _parse_sym(f, tk->symbol, 0);
    if (ret == ERROR)
        return ERROR;
    /* printf("%i\n", strlen(tk->number->num)); */
    /* printf(tk->number->num); */
    return ret;
}

#endif

