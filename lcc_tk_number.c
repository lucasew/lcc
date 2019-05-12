#ifndef LCC_TOKEN_NUMBER
#define LCC_TOKEN_NUMBER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"
#include "lcc_parser_until.c"

enum lcc_tk_number_type {
    i8,
    i16,
    i32,
    i64,
    i128
};

struct lcc_tk_number {
    char *num;
    enum lcc_tk_number_type type;
};


int _number_validator(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

int lcc_tk_number__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->number = malloc(sizeof(struct lcc_tk_number));
    if (tk->number == NULL)
        return ERROR;
    tk->type = NUMBER;
    int ret = _parse_until(&tk->number->num ,f, _number_validator, 0);
    if (ret == ERROR)
        return ERROR;
    /* printf("%i\n", strlen(tk->number->num)); */
    /* printf(tk->number->num); */
    tk->number->type = i64;
    return ret;
}

#endif

