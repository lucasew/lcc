#ifndef LCC_TOKEN
#define LCC_TOKEN

enum lcc_token_type {
    BANG,
    BLOCK,
    COMMA,
    DOT,
    HASH,
    NEWLINE,
    NUMBER,
    OP,
    SEMICOLON,
    SPACE,
    STRING,
    STRING_LITERAL,
    SYMBOL,
    TEOF,
    BACKSLASH,
    ECOMMERCIAL,
    UNDEFINED
};


struct lcc_token {
    enum lcc_token_type type;
    union {
        struct lcc_tk_undefined *undefined;
        struct lcc_tk_number    *number;
        struct lcc_tk_str       *str;
        struct lcc_tk_op        *op;
        struct lcc_tk_symbol    *symbol;
        struct lcc_tk_block     *block;
    };
};
#include "lcc_tk_number.c"
#include "lcc_tk_str.c"
#include "lcc_tk_strliteral.c"
#include "lcc_tk_undefined.c"
/* #include "lcc_tk_space.c" */
/* #include "lcc_tk_newline.c" */
/* #include "lcc_tk_eof.c" */
#include "lcc_tk_op.c"
/* #include "lcc_tk_semicolon.c" */
#include "lcc_tk_symbol.c"
/* #include "lcc_tk_hash.c" */
#include "lcc_tk_block.c"
/* #include "lcc_tk_comma.c" */
/* #include "lcc_tk_dot.c" */
/* #include "lcc_tk_bang.c" */

#endif
