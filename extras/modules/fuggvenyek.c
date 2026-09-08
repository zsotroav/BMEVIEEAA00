#include <stdio.h>

void hello() {
    echo("Hello, world!");
}

void border(int s) {
    printf("+");
    for (int i = 0; i < s; ++i) printf("-");
    printf("+\n");
}

int pw(int b, int p) {
    int re = 1;
    for (int i = 0; i < p; ++i) re *= b;
    return re;
}

void echo(char* string) {
    border(string_length(string));
    printf("|%s|\n", string);
    border(string_length(string));
}

void num(int n) {
    printf("%d\n", n);
}

int string_length(char* string) {
    int l = 0;
    while (string[l] != '\0') l++;
    return l;
}

int fac(int a) {
    int re = 1;
    for (int i = a; i > 0; --i) re *= i;
    return re;
}