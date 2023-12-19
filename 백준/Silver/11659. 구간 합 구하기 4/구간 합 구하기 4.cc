#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    int S[N]{};
    int tmp=0, sum=0;

    for(int i=1; i<=N; i++) {
        cin >> tmp;
        sum += tmp;
        S[i] = sum;
    }

    for(int i=1; i<=M; i++) {
        int x, y; cin >> x >> y;
        cout << S[y]-S[x-1] << '\n'; 
    }

    return 0;
}