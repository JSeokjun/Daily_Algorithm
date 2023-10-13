#include <iostream>
using namespace std;

uint64_t mod_add(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = a%m + b%m;
    
    if(a<m && b<m && a >= m-b) return r - m;
    else return r;
}

uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = 0;

    while(b > 0) {
        if(b & 1) r = mod_add(r, a, m);
        b = b >> 1;
        a = mod_add(a, a, m);
    }
    return r;
}

uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t m)
{
    uint64_t r = 1;

    while(b > 0) {
        if(b & 1) r = mod_mul(r, a, m);
        b = b >> 1;
        a = mod_mul(a, a, m);
    }
    return r;
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    cout << mod_pow(A, B, C);

    return 0;
}   