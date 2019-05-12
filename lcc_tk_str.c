#ifndef LCC_TOKEN_STRING
#define LCC_TOKEN_STRING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"
#include "lcc_parser_until.c"

struct lcc_tk_str {
    char *str;
};


int _str_validator(char c) {
    return c != '"';
}

int lcc_tk_str__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->str = malloc(sizeof(struct lcc_tk_str));
    if (tk->str == NULL)
        return ERROR;
    char unget;
    lcc_input__getc(f, &unget); // Excludes the first "
    int ret = _parse_until(&tk->str->str, f, _str_validator, 0);
    if (ret == ERROR)
        return ERROR;
    /* printf("%i\n", strlen(tk->number->num)); */
    unget = tk->str->str[strlen(tk->str->str)];
    lcc_input__ungetc(f, unget);
    /* printf(tk->number->num); */
    return ret;
}

#endif

