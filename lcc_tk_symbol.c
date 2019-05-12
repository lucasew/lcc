#ifndef LCC_TOKEN_SYMBOL
#define LCC_TOKEN_SYMBOL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"
#include "lcc_parser_until.c"

struct lcc_tk_symbol {
    char *str;
};


int _symbol_validator(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9');
}

int lcc_tk_sym__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->str = malloc(sizeof(struct lcc_tk_str));
    if (tk->str == NULL)
        return ERROR;
    tk->type = SYMBOL;
    /* printf("%i\n", strlen(tk->number->num)); */
    /* printf(tk->number->num); */
    return _parse_until(&tk->str->str, f, _symbol_validator, 0);
}

#endif

