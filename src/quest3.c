#include <stdio.h>
int fibonacci(int N);

int main() {
    int N;
    int x;
    scanf("%d", &N);
    if (N < 0)
        printf("n/a");
    else if (N == 0)
        printf("0");
    else
        printf("%d", fibonacci(N));
    return 0;
}

int fibonacci(int N) {
    if (N == 1 || N == 2) return 1;
    return fibonacci(N - 1) + fibonacci(N - 2);
}
