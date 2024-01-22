#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define mod 1000000000
map<int, int> M;

int F(int x) {
    if(x == 0) return 0;
    else if(x == 1) return 1;

    else if(x > 1) {
        if(!M[x-1] && !M[x-2]) {
            M[x-1] = F(x-1) % mod; 
            M[x-2] = F(x-2) % mod;
        }
        else if(!M[x-1]) M[x-1] = F(x-1) % mod;
        else if(!M[x-2]) M[x-2] = F(x-2) % mod;

        return (M[x-1] + M[x-2]) % mod; 
    } 
    else {
        if(!M[x+2] && !M[x+1]) {
            M[x+2] = F(x+2) % mod; 
            M[x+1] = F(x+1) % mod;
        }
        else if(!M[x+2]) M[x+2] = F(x+2) % mod;
        else if(!M[x+1]) M[x+1] = F(x+1) % mod;

        return (M[x+2] - M[x+1]) % mod; 
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;

    int result = F(n);
    if(result > 0) cout << 1 << '\n' << result % mod;
    else if(result == 0) cout << 0 << '\n' << 0;
    else cout << -1 << '\n' << result * -1 % mod;

    return 0;
}   