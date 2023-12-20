#include <iostream>
using namespace std;

int mod_add(int a, int b) {
    int r = a%10 + b%10;

    if(r >= 10) return r - 10;
    else return r;
}

int mod_mul(int a, int b) {
    int r = 0;

    while(b > 0) {
        if(b & 1) r = mod_add(r, a);
        b = b >> 1;
        a = mod_add(a, a);
    }

    return r;
}

int mod_pow(int a, int b) {
    int r = 1;

    while(b > 0) {
        if(b & 1) r = mod_mul(r, a);
        b = b >> 1;
        a = mod_mul(a, a);
    }

    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T; cin >> T;
    
    for (int i=0; i<T; i++) {
        int a, b, r; cin >> a >> b;
        r = mod_pow(a, b);
        if(r==0) cout << 10 << '\n';
        else cout << r << '\n';
    }
    
    return 0;
}