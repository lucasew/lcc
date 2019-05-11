#ifndef LCC_TOKEN_NUMBER
#define LCC_TOKEN_NUMBER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcc_status.h"
#include "limits.h"
#include "lcc_token.c"
#include "lcc_input_gather.c"

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


static inline int 
_parse_number(struct lcc_input_wrapper *f, struct lcc_tk_number *tk, int i) {
    char c;
    lcc_input__getc(f, &c);
    if ((c >= '0' && c <= '9') || c == '.') {
        int res = _parse_number(f, tk, i + 1);
        tk->num[i] = c;
        return res;
    }
    tk->num = malloc(sizeof(char)*(i + 2));
    if (tk->num == NULL)
        return ERROR;
    tk->num[i] = '\0';
    lcc_input__ungetc(f, c);
    return SUCESS;
}

int lcc_tk_number__parse(struct lcc_input_wrapper *f, struct lcc_token *tk) {
    tk->number = malloc(sizeof(struct lcc_tk_number));
    if (tk->number == NULL)
        return ERROR;
    tk->type = NUMBER;
    int ret = _parse_number(f, tk->number, 0);
    if (ret == ERROR)
        return ERROR;
    /* printf("%i\n", strlen(tk->number->num)); */
    /* printf(tk->number->num); */
    tk->number->type = i64;
    return ret;
}

#endif

