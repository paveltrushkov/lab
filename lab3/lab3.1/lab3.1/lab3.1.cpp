﻿#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        putchar(c);
    }
    return 0;
}