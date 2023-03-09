#include <stdio.h>
#include <math.h>

int del(int a, int b){
    int iter = 0;
    while (a >=b) {
        a = a - b;
        ++iter;
    }
    return iter;
}

int delest(int a, int b){
    int iter = 0;
    while (a>= b){
        a = a -b;
        ++iter;
    }
    return a;
}

int result (int a) {
    if (a < 0) {
        a = -a;
    }
    int y;
    int i = 2;
    y = a; 
    while (a != 1){
        if (delest(a,i) == 0){
            y = i;
            a = del(a, i);
        } else if (i + i > a) {
            i = a;
        } else 
        ++i;
    }
    return y;
}

int main() {
    int rez, in;
    char testc;
    int screz = scanf("%d%c", &in, &testc);
    if (screz == 2 && testc == '\n' && in != 0) {
        rez = result(in);
        printf("%d", rez);
    } else
        printf("n/a");
}