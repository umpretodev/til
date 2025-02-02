#include <iostream>
using namespace std;

int fibonacci(int n) {
    int n1, n2, n3;

    n1 = 1;
    n2 = 1;

    if (n < 3) {
        return 1;
    }

    for (int i = 3; i <= n; i++) {
        n3 = n1 + n2;

        n1 = n2;
        n2 = n3;
    }

    return n3;
}

int main() {
    int n;

    printf("Informe n: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}