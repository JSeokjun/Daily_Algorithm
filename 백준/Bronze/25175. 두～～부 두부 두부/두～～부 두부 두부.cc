#include <iostream>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    if(K-3>0) {
        for(int i=0; i<K-3; i++) {
            if(M==N) M=1;
            else M++;
        }
    }
    else if(K-3<0) {
        for(int i=0; i>K-3; i--) {
            if(M==1) M=N;
            else M--;
        }
    }
    cout << M;
}