#ifndef LCC_TOKEN_PRETTYPRINT
#define LCC_TOKEN_PRETTYPRINT
#include "lcc_token_stack.c"
#include "lcc_token.c"
#include "lcc_tk_undefined.c"

void lcc_token_block__prettyprint(struct lcc_token tk) {
    printf("BLOCK: ");
    if(tk.block->openess == OPEN)
        printf("OPEN ");
    else
        printf("CLOSE ");
    switch(tk.block->type) {
        case ANGULAR:       printf("ANGULAR");break;
        case CURLY:         printf("CURLY");break;
        case PARENTHESIS:   printf("PARENTHESIS");break;
        case SQUARE:        printf("SQUARE");break;
    }
    printf("\n");
}

void
lcc_token__prettyprint(struct lcc_token tk) {
    switch (tk.type) {
        case UNDEFINED:         printf("UNDEF: '%c' (%i)\n", tk.undefined->c, tk.undefined->c);break;
        case NUMBER:            printf("NUMBER: '%s'\n", tk.number->num);break;
        case STRING:            printf("STRING: '%s'\n", tk.str->str);break;
        case SPACE:             printf("SPACE: ' '\n");break;
        case NEWLINE:           printf("NEWLINE: '\\n' \n");break;
        case TEOF:              printf("EOF:\n");break;
        case SEMICOLON:         printf("SEMICOLON: ';'\n");break;
        case SYMBOL:            printf("SYMBOL: '%s'\n", tk.str->str);break;
        case HASH:              printf("HASH: '#' \n");break;
        case BLOCK:             lcc_token_block__prettyprint(tk);break;
        case COMMA:             printf("COMMA: ',' \n");break;
        case BANG:              printf("BANG: '!'\n");break;
        case DOT:               printf("DOT: '.'\n");break;
        case STRING_LITERAL:    printf("STRING_LITERAL: '%s'\n", tk.str->str);break;
        case BACKSLASH:         printf("BACKSLASH: '\\' \n");break;
        case ECOMMERCIAL:       printf("E_COMMERCIAL: '&'\n");break;
        case ATTRIB:            printf("ATTRIB: '='\n");break;
        case DIV:               printf("DIV: '/'\n");break;
        case MUL:               printf("MUL: '*'\n");break;
        case PIPE:              printf("PIPE: '|'\n");break;
        case SUB:               printf("SUB: '-'\n");break;
        case SUM:               printf("SUM: '+'\n");break;
        default:                printf("TOKEN NOT RECOGNIZED '%i'\n", tk.type);
    }
    /* free(tk.undefined); // all pointers point to the same address */
}

#endif

