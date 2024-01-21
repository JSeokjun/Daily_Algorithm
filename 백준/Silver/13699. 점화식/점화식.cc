#include <iostream>
using namespace std;

long long m[36];

long long dp(int x) {
    if(x==0 || x==1) return 1;
    else {
        long long tmp = 0;
        for(int i=0; i<x/2; i++) {
            if(m[i] && m[x-1-i]) tmp += m[i]*m[x-1-i];
            else if(m[i]) {
                m[x-1-i] = dp(x-1-i); 
                tmp += m[i]*m[x-1-i];
            }
            else if(m[x-1-i]) {
                m[i] = dp(i);
                tmp += m[i]*m[x-1-i];
            }
            else {
                m[x-1-i] = dp(x-1-i);
                m[i] = dp(i);
                tmp += m[i]*m[x-1-i];
            } 
        }
        if(x%2 == 0) return tmp*2;
        else {
            if(m[x/2]) return tmp*2 + m[x/2]*m[x/2];
            else {
                m[x/2] = dp(x/2);
                return tmp*2 + m[x/2]*m[x/2];
            } 
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    cout << dp(n);

    return 0;
}   