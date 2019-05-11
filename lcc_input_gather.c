#ifndef LCC_INPUT_GATHER
#define LCC_INPUT_GATHER
#include <stdio.h>
#include <stdlib.h>
#include "lcc_status.h"

struct lcc_input_wrapper {
    FILE *f;
    char last;
};

struct lcc_input_wrapper *lcc_input__init(FILE *f) {
    struct lcc_input_wrapper *ret = malloc(sizeof(struct lcc_input_wrapper));
    ret->f = f;
    ret->last = fgetc(f);
    return ret;
}

void lcc_input__destroy(struct lcc_input_wrapper *self) {
    free(self);
}

int lcc_input__getc(struct lcc_input_wrapper *self, char *c) {
    if (self->last != 0) {
        *c = self->last;
        self->last = 0;
        return SUCESS;
    }
    if (feof(self->f))
        return ERROR;
    *c = getc(self->f);
    return SUCESS;
}

int lcc_input__ungetc(struct lcc_input_wrapper *self, char c) {
    self->last = c;
    return SUCESS;
}

#endif
