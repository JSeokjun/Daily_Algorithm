#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    string C; cin >> C;
    char C_tmp[N];
    int r=0, g=0, b=0;

    while(K--) {
        for(int i=0; i<N; i++) {
            for(int j=i-1; j<=i+1; j++) {
                if(i==0) {
                    if(j == i-1) {
                        if(C[N-1]=='R') r++;
                        else if(C[N-1]=='G') g++;
                        else b++;    
                    }
                    else {
                        if(C[j]=='R') r++;
                        else if(C[j]=='G') g++;
                        else b++;
                    }
                }
                else if(i==N-1) {
                    if(j == i+1) {
                        if(C[0]=='R') r++;
                        else if(C[0]=='G') g++;
                        else b++;    
                    }
                    else {
                        if(C[j]=='R') r++;
                        else if(C[j]=='G') g++;
                        else b++;
                    }
                }
                else {
                    if(C[j]=='R') r++;
                    else if(C[j]=='G') g++;
                    else b++;
                }
            }

            if(r==3 || g==3 || b==3 || r==1&&g==1&&b==1) C_tmp[i] = 'B';
            else if(r==2&&g==1 || g==2&&b==1 || b==2&&r==1) C_tmp[i] = 'R';
            else C_tmp[i] = 'G';

            r=0, g=0, b=0;
        }

        for(int i=0; i<N; i++) {
            C[i] = C_tmp[i];
        }
    }
    
    for(int i=0; i<N; i++) {
        if(C[i]=='R') r++;
        else if(C[i]=='G') g++;
        else b++;
    }

    cout << r << ' ' << g << ' ' << b;

    return 0;
}   