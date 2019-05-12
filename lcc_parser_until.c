#ifndef LCC_PARSER_UTIL
#define LCC_PARSER_UTIL
#include <stdlib.h>
#include "lcc_input_gather.c"

static inline int 
_parse_until(char **str, struct lcc_input_wrapper *f, int (*validator)(char c), int i) {
    char c;
    lcc_input__getc(f, &c);
    if (validator(c)) { // if \\ go anyway, escape :p
        if (c == '\\')
            lcc_input__getc(f, &c);
        int res = _parse_until(str, f, validator, i + 1);
        if(res == SUCESS)
            *(*str + i) = c;
        return res;
    }
    *str = malloc(sizeof(char)*(i + 2));
    if (*str == NULL)
        return ERROR;
    *(*str + i) = '\0';
    lcc_input__ungetc(f, c);
    return SUCESS;
}

#endif
