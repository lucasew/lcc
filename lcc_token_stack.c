#ifndef LCC_TOKEN_STACK
#define LCC_TOKEN_STACK

#include <stdlib.h>
#include <stdio.h>
#include "lcc_token.c"
#include "lcc_status.h"

struct lcc_token_stack {
    int cursor;
    struct lcc_token **tokens;
    int size;
};

struct lcc_token_stack*
lcc_token_stack__new(int size, int step) {
    struct lcc_token_stack *ret = malloc(sizeof(struct lcc_token_stack));
    ret->cursor = 0;
    ret->size = size;
    ret->tokens = malloc(sizeof(struct lcc_token*)*size);
    return ret;
}

void
lcc_token_stack__destroy(struct lcc_token_stack *self) {
    while (self->cursor == 0) {
        free(self->tokens[self->cursor]);
        self->cursor--;
    }
    free(self->tokens);
    free(self);
}

static inline int
lcc_token_stack__extend(struct lcc_token_stack *self) {
    printf("SIZE: %i\n", self->size*2);
    self->size *= 2;
    return realloc(self->tokens, sizeof(struct lcc_token)*self->size) != NULL
        ? SUCESS
        : ERROR;
}

int
lcc_token_stack__push(struct lcc_token_stack *self, struct lcc_token token) {
    printf("-");
    if (self->size == self->cursor)
        if (lcc_token_stack__extend(self) == ERROR) {
            lcc_token_stack__destroy(self); // Safe shutdown
            return ERROR;
        }
    self->tokens[self->cursor] = malloc(sizeof(struct lcc_token*));
    *self->tokens[self->cursor] = token;
    self->cursor++;
    return SUCESS;
}

struct lcc_token
lcc_token_stack__pop(struct lcc_token_stack *self) {
    struct lcc_token tk = *self->tokens[self->cursor];
    free(self->tokens[self->cursor]);
    self->cursor--;
    return tk;
}

#endif
