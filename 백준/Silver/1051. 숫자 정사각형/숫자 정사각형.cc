#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    char arr[N][M];

    for(int i=0; i<N; i++) {
        string tmp; cin >> tmp;
        for(int j=0; j<M; j++) {
            arr[i][j] = tmp[j];
        }
    }

    int maxLen = 0;

    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            for(int k=j+1; k<M; k++) {
                if(arr[i][j]==arr[i][k] && k-j>maxLen) {
                    char tmp = arr[i][j];
                    int len = k - j;
                    if(i+len<N && arr[i+len][j]==tmp && arr[i+len][k]==tmp) {
                        maxLen = len;
                    }
                } 
            }
        }
    }

    cout << (maxLen+1)*(maxLen+1);

    return 0;
}