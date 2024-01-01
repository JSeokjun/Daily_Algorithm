#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int B[20][20], C=0, cnt=0, row=0, col=0;
    
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            cin >> B[i][j];
        }
    }

    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            if(cnt == 5 && C != B[i][j]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }

            if(C != B[i][j]) cnt = 0;

            if(B[i][j]==1 || B[i][j]==2) {
                C = B[i][j];
                cnt++;
                if(cnt == 1) {
                    row = i; col = j;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
        C=0, cnt=0, row=0, col=0;
    }

    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            if(cnt == 5 && C != B[j][i]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }
            
            if(C != B[j][i]) cnt = 0;

            if(B[j][i]==1 || B[j][i]==2) {
                C = B[j][i];
                cnt++;
                if(cnt == 1) {
                    row = j; col = i;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
        C=0, cnt=0, row=0, col=0;
    }

    for(int i=0; i<15; i++) {
        for(int j=1+i; j<=19; j++) {
            if(cnt == 5 && C != B[j][j-i]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }
            
            if(C != B[j][j-i]) cnt = 0;

            if(B[j][j-i]==1 || B[j][j-i]==2) {
                C = B[j][j-i];
                cnt++;
                if(cnt == 1) {
                    row = j; col = j-i;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
        C=0, cnt=0, row=0, col=0;
    }

    for(int i=1; i<=14; i++) {
        for(int j=1+i; j<=19; j++) {
            if(cnt == 5 && C != B[j-i][j]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }
            
            if(C != B[j-i][j]) cnt = 0;

            if(B[j-i][j]==1 || B[j-i][j]==2) {
                C = B[j-i][j];
                cnt++;
                if(cnt == 1) {
                    row = j-i; col = j;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
        C=0, cnt=0, row=0, col=0;
    }

    for(int i=0; i<15; i++) {
        for(int j=1+i; j<=19; j++) {
            if(cnt == 5 && C != B[j][20-j+i]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }
            
            if(C != B[j][20-j+i]) cnt = 0;

            if(B[j][20-j+i]==1 || B[j][20-j+i]==2) {
                C = B[j][20-j+i];
                cnt++;
                if(cnt == 5) {
                    row = j; col = 20-j+i;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
        C=0, cnt=0, row=0, col=0;
    }

    for(int i=0; i<14; i++) {
        for(int j=18-i; j>=1; j--) {
            if(cnt == 5 && C != B[19-j-i][j]) {
                cout << C << '\n' << row << ' ' << col;
                return 0;
            }
            
            if(C != B[19-j-i][j]) cnt = 0;

            if(B[19-j-i][j]==1 || B[19-j-i][j]==2) {
                C = B[19-j-i][j];
                cnt++;
                if(cnt == 5) {
                    row = 19-j-i; col = j;
                }
            }
        }
        if(cnt == 5) {
            cout << C << '\n' << row << ' ' << col;
            return 0;
        }
    }

    cout << 0;
    
    return 0;
}