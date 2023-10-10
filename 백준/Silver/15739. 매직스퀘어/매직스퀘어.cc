#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int M[N][N], sum=N*(N*N+1)/2, tmp=0;
    bool check[N*N+1];
    
    for(int i=1; i<=N*N+1; i++) check[i]=0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> M[i][j];
            if(check[M[i][j]]==1) {
                cout << "FALSE";
                return 0;
            }
            check[M[i][j]]=1;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp += M[i][j];
        }
        if(tmp!=sum) {
            cout << "FALSE";
            return 0;
        }
        tmp=0;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tmp += M[j][i];
        }
        if(tmp!=sum) {
            cout << "FALSE";
            return 0;
        }
        tmp=0;
    }

    for(int i=0; i<N; i++) {
        tmp+=M[i][i];
    }
    if(tmp!=sum) {
        cout << "FALSE";
        return 0;
    }
    tmp=0;

    for(int i=0; i<N; i++) {
        tmp+=M[i][N-1-i];
    }
    if(tmp!=sum) {
        cout << "FALSE";
        return 0;
    }

    cout << "TRUE";
    return 0;
}   