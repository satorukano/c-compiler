#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include"9cc.h"

// char *user_input;

// Token *token;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "引数の個数が正しくありません");
        return 1;
    }

    token = tokenize(argv[1]);
    user_input = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf(" mov rax, %d\n", expect_number());

    while (!at_eof())
    {
        if (consume('+'))
        {
            printf(" add rax, %d\n", expect_number());
            continue;
        }

        expect('-');
        printf(" sub rax, %d\n", expect_number());
    }
    printf(" ret\n");
    return 0;
}
