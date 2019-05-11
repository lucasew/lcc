#ifndef LCC_TOKEN_PRETTYPRINT
#define LCC_TOKEN_PRETTYPRINT
#include "lcc_token_stack.c"
#include "lcc_token.c"
#include "lcc_tk_undefined.c"

void lcc_token_op__prettyprint(struct lcc_token tk) {
    printf("OP: ");
    switch(tk.op->type) {
        case SUM: printf("SUM");break;
        case SUB: printf("SUB");break;
        case MUL: printf("MUL");break;
        case DIV: printf("DIV");break;
        case ATTRIB: printf("ATTRIB");break;
        default: printf("UNKNOWN");break;
    }
    printf("\n");
}

void
lcc_token__prettyprint(struct lcc_token tk) {
    switch (tk.type) {
        case UNDEFINED:     printf("UNDEF: '%c' (%i)\n", tk.undefined->c, tk.undefined->c);break;
        case NUMBER:        printf("NUMBER: %s\n", tk.number->num);break;
        case STRING:        printf("STRING: %s\n", tk.str->str);break;
        case SPACE:         printf("SPACE:\n");break;
        case NEWLINE:       printf("NEWLINE:\n");break;
        case TEOF:          printf("EOF:\n");break;
        case OP:            lcc_token_op__prettyprint(tk);break;
        case SEMICOLON:     printf("SEMICOLON:\n");break;
        case SYMBOL:        printf("SYMBOL: %s\n", tk.symbol->str);break;
        default:            printf("TOKEN NOT RECOGNIZED (%i)\n", tk.type);
    }
    /* free(tk.undefined); // all pointers point to the same address */
}

#endif

