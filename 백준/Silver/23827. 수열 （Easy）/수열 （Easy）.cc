#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int arr[N];
    long long int result = 0;
    for(int i=0; i<N; i++) {
        int tmp; cin >> tmp;
        arr[i] = tmp;
    }

    long long int S[N], sum = 0;
    for(int i=0; i<N-1; i++) {
        sum += arr[N-1-i];
        S[i] = sum;
    }

    for(int i=0; i<N-1; i++) {
        long long int tmp = arr[N-2-i] * S[i] % 1000000007;
        result += tmp % 1000000007;
    }

    cout << result % 1000000007;
}