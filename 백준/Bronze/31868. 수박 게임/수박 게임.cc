#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    N = (int)pow(2,N-1);
    
    if(N > K) cout << 0;
    else cout << K / N;

    return 0;
}