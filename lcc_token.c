#ifndef LCC_TOKEN
#define LCC_TOKEN

enum lcc_token_type {
    SPACE,
    NEWLINE,
    UNDEFINED,
    NUMBER,
    STRING,
    TEOF
};

struct lcc_token {
    enum lcc_token_type type;
    union {
        struct lcc_tk_undefined *undefined;
        struct lcc_tk_number    *number;
        struct lcc_tk_str       *str;
    };
};

#include "lcc_tk_number.c"
#include "lcc_tk_str.c"
#include "lcc_tk_undefined.c"
#include "lcc_tk_space.c"
#include "lcc_tk_newline.c"
#include "lcc_tk_eof.c"

#endif
