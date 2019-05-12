#ifndef LCC_TOKEN_PARSER
#define LCC_TOKEN_PARSER

#include <assert.h>
#include "lcc_token.c"
#include "lcc_status.h" 
#include "lcc_input_gather.c"

const int handlers[] = {
    TEOF, // 'EOF (-1)'
    UNDEFINED, // '' (0)
    UNDEFINED, // '' (1)
    UNDEFINED, // '' (2)
    UNDEFINED, // '' (3)
    UNDEFINED, // '' (4)
    UNDEFINED, // '' (5)
    UNDEFINED, // '' (6)
    UNDEFINED, // '' (7)
    UNDEFINED, // '' (8)
    UNDEFINED, // '' (9)
    NEWLINE, // '\n' (10)
    UNDEFINED, // '' (11)
    UNDEFINED, // '' (12)
    UNDEFINED, // '' (13)
    UNDEFINED, // '' (14)
    UNDEFINED, // '' (15)
    UNDEFINED, // '' (16)
    UNDEFINED, // '' (17)
    UNDEFINED, // '' (18)
    UNDEFINED, // '' (19)
    UNDEFINED, // '' (20)
    UNDEFINED, // '' (21)
    UNDEFINED, // '' (22)
    UNDEFINED, // '' (23)
    UNDEFINED, // '' (24)
    UNDEFINED, // '' (25)
    UNDEFINED, // '' (26)
    UNDEFINED, // '' (27)
    UNDEFINED, // '' (28)
    UNDEFINED, // '' (29)
    UNDEFINED, // '' (30)
    UNDEFINED, // '' (31)
    SPACE, // ' ' (32)
    BANG, // '!' (33)
    STRING, // '"' (34)
    HASH, // '#' (35)
    UNDEFINED, // '$ (36)
    UNDEFINED, // '%' (37)
    ECOMMERCIAL, // '&' (38)
    STRING_LITERAL, // ''' (39)
    BLOCK, // '(' (40)
    BLOCK, // ')' (41)
    OP, // '*' (42)
    OP, // '+' (43)
    COMMA, // ',' (44)
    OP, // '-' (45)
    DOT, // '.' (46)
    OP, // '/' (47)
    NUMBER, // '0' (48)
    NUMBER, // '1' (49)
    NUMBER, // '2' (50)
    NUMBER, // '3' (51)
    NUMBER, // '4' (52)
    NUMBER, // '5' (53)
    NUMBER, // '6' (54)
    NUMBER, // '7' (55)
    NUMBER, // '8' (56)
    NUMBER, // '9' (57)
    UNDEFINED, // ':' (58)
    SEMICOLON, // ';' (59)
    BLOCK, // '<' (60)
    OP, // '=' (61)
    BLOCK, // '>' (62)
    UNDEFINED, // '?' (63)
    UNDEFINED, // '@' (64)
    SYMBOL, // 'A' (65)
    SYMBOL, // 'B' (66)
    SYMBOL, // 'C' (67)
    SYMBOL, // 'D' (68)
    SYMBOL, // 'E' (69)
    SYMBOL, // 'F' (70)
    SYMBOL, // 'G' (71)
    SYMBOL, // 'H' (72)
    SYMBOL, // 'I' (73)
    SYMBOL, // 'J' (74)
    SYMBOL, // 'K' (75)
    SYMBOL, // 'L' (76)
    SYMBOL, // 'M' (77)
    SYMBOL, // 'N' (78)
    SYMBOL, // 'O' (79)
    SYMBOL, // 'P' (80)
    SYMBOL, // 'Q' (81)
    SYMBOL, // 'R' (82)
    SYMBOL, // 'S' (83)
    SYMBOL, // 'T' (84)
    SYMBOL, // 'U' (85)
    SYMBOL, // 'V' (86)
    SYMBOL, // 'W' (87)
    SYMBOL, // 'X' (88)
    SYMBOL, // 'Y' (89)
    SYMBOL, // 'Z' (90)
    BLOCK, // '[' (91)
    BACKSLASH, // '\' (92)
    BLOCK, // ']' (93)
    UNDEFINED, // '^' (94)
    SYMBOL, // '_' (95)
    UNDEFINED, // '`' (96)
    SYMBOL, // 'a' (97)
    SYMBOL, // 'b' (98)
    SYMBOL, // 'c' (99)
    SYMBOL, // 'd' (100)
    SYMBOL, // 'e' (101)
    SYMBOL, // 'f' (102)
    SYMBOL, // 'g' (103)
    SYMBOL, // 'h' (104)
    SYMBOL, // 'i' (105)
    SYMBOL, // 'j' (106)
    SYMBOL, // 'k' (107)
    SYMBOL, // 'l' (108)
    SYMBOL, // 'm' (109)
    SYMBOL, // 'n' (110)
    SYMBOL, // 'o' (111)
    SYMBOL, // 'p' (112)
    SYMBOL, // 'q' (113)
    SYMBOL, // 'r' (114)
    SYMBOL, // 's' (115)
    SYMBOL, // 't' (116)
    SYMBOL, // 'u' (117)
    SYMBOL, // 'v' (118)
    SYMBOL, // 'w' (119)
    SYMBOL, // 'x' (120)
    SYMBOL, // 'y' (121)
    SYMBOL, // 'z' (122)
    BLOCK, // '{' (123)
    PIPE, // '|' (124)
    BLOCK, // '}' (125)
    UNDEFINED, // '~' (126)
    UNDEFINED, // 'DEL' (127)

};

typedef int (*lcc_token_handler)(struct lcc_input_wrapper *in, struct lcc_token *tk);

lcc_token_handler lcc_get_appropriate_handler(char c) {
    enum lcc_token_type handler = handlers[c + 1];
    switch (handler) {
        case BLOCK: return lcc_tk_block__parse;
        case NUMBER: return lcc_tk_number__parse;
        case OP: return lcc_tk_op__parse;
        case STRING_LITERAL: return lcc_tk_str_literal__parse;
        case STRING: return lcc_tk_str__parse;
        case SYMBOL: return lcc_tk_sym__parse;
        case UNDEFINED: return lcc_tk_undefined__parse;
        default: return NULL;
    }
    return NULL;
}

int lcc_parse_tokens(struct lcc_input_wrapper *input, struct lcc_token *tk) {
    char c = 0;
    if (lcc_input__getc(input, &c) == ERROR)
        return ERROR;
    /* printf("PARSED: '%c'\n", c); */
    lcc_input__ungetc(input, c);
    /* if (c > 127 || c < 0) */
    /*     return lcc_tk_undefined__parse(input, tk); */
    tk->type = handlers[c + 1];
    lcc_token_handler parser = lcc_get_appropriate_handler(c);
    if (parser != NULL) {
        return parser(input, tk);
    }
    lcc_input__getc(input, &c);
    return SUCESS;
}
#endif
