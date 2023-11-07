#include <iostream>
using namespace std;

int fib[1000001];

int fibonacci(int n) {
    if(n==0) return 0;
    if(n==1) return 1;

    if(fib[n-1] == 0) {
        fib[n-1] = fibonacci(n-1);
    }
    if(fib[n-2] == 0) {
        fib[n-2] = fibonacci(n-2);
    }

    fib[n] = fib[n-1] + fib[n-2];

    return fib[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    cout << fibonacci(N) % 1000000007;

    return 0;
}   