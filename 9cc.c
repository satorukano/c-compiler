#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include"9cc.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "引数の個数が正しくありません");
        return 1;
    }


    token = tokenize(argv[1]);
    user_input = argv[1];
    program();

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");

    printf(" push rbp\n");
    printf(" mov rbp, rsp\n");
    printf(" sub rsp, 208\n");

    for (int i = 0; code[i]; i++) {
        gen(code[i]);

        printf(" pop rax\n");
    }

    printf(" mov rsp, rbp\n");
    printf(" pop rbp\n");
    printf(" ret\n");
    return 0;
}
