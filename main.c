#include <stdio.h>
#include "lcc_token_stack.c"
#include "lcc_token.c"
#include "lcc_token_parser.c"
#include "lcc_token_prettyprint.c"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Especifique um arquivo!\n");
        return 0;
    }
    FILE *input = fopen(argv[1], "r");
    struct lcc_input_wrapper *in = lcc_input__init(input);
    struct lcc_token tk;
    while(lcc_parse_tokens(in, &tk) == SUCESS) {
        lcc_token__prettyprint(tk);
    }
    fclose(input);
}
