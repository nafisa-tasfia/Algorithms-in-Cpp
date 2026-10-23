#include <iostream>
using namespace std;

// Recursive Fibonacci
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// Memoization Fibonacci
int fib_mem(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];

    memo[n] = fib_mem(n - 1, memo) + fib_mem(n - 2, memo);
    return memo[n];
}

int fib_memoization(int n) {
    int *memo = new int[n + 1];

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    int result = fib_mem(n, memo);
    delete[] memo;

    return result;
}

int main() {
    int n = 11;

    cout << "Fibonacci(" << n << "): " << endl;
    cout << "Recursive: " << fib_rec(n) << endl;
    cout << "Memoization: " << fib_memoization(n) << endl;

    return 0;
}
