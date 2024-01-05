#include <iostream>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M >> K;
    bool eungae[N]{0};
    int count[N]{0}, num;

    for(int i=0; i<M; i++) {
        int idx; cin >> idx;
        eungae[idx] = 1;
    }
    num = M;

    while(K--) {
        num = 0;

        for(int i=0; i<N; i++) {
            if(eungae[i] == 1) {
                if(i == 0) {
                    count[N-1]++;
                    count[1]++;
                }
                else if(i == N-1) {
                    count[0]++;
                    count[N-2]++;
                }
                else {
                    count[i-1]++;
                    count[i+1]++;
                }
            }
        }

        for(int i=0; i<N; i++) {
            if(count[i] == 1) {
                eungae[i] = 1;
                num++;
            }
            else eungae[i] = 0; 
        }

        memset(count, 0, sizeof(count));
    }

    cout << num;

    return 0;
}