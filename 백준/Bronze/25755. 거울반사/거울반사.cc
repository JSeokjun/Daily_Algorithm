#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    char W; int N;
    cin >> W >> N;
    int arr[N][N];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    if(W=='D' || W=='U') {
        for(int i=N-1; i>=0; i--) {
            for(int j=0; j<N; j++) {
                if(arr[i][j]==3 || arr[i][j]==4 || arr[i][j]==6 
                    || arr[i][j]==7 || arr[i][j]==9) cout << '?' << ' ';
                else if(arr[i][j]==2) cout << 5 << ' ';
                else if(arr[i][j]==5) cout << 2 << ' ';
                else cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else if(W=='L' || W=='R') {
        for(int i=0; i<N; i++) {
            for(int j=N-1; j>=0; j--) {
                if(arr[i][j]==3 || arr[i][j]==4 || arr[i][j]==6 
                    || arr[i][j]==7 || arr[i][j]==9) cout << '?' << ' ';
                else if(arr[i][j]==2) cout << 5 << ' ';
                else if(arr[i][j]==5) cout << 2 << ' ';
                else cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }  
    
    return 0;
}   