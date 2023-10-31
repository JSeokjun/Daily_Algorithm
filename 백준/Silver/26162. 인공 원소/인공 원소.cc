#include <iostream>
#include <math.h>
using namespace std;

int mod_add(int a, int b, int m)
{
    int r = a%m + b%m;
    
    if(a<m && b<m && a >= m-b) return r - m;
    else return r;
}

int mod_mul(int a, int b, int m)
{
    int r = 0;

    while(b > 0) {
        if(b & 1) r = mod_add(r, a, m);
        b = b >> 1;
        a = mod_add(a, a, m);
    }
    return r;
}

int mod_pow(int a, int b, int m)
{
    int r = 1;

    while(b > 0) {
        if(b & 1) r = mod_mul(r, a, m);
        b = b >> 1;
        a = mod_mul(a, a, m);
    }
    return r;
}

int a[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

int miller_rabin(int n)
{
    if(n == 2) return 1;
    else if(n%2==0 || n<=1) return 0;
    for(int i=0; i<12; i++) {
        if(n == a[i]) return 1;
    }
    
    int k=0, q=n-1, tmp;

    while(q%2 == 0) {
        q/=2;
        k++;
    }

    for(int i=0; i<12; i++) {
        int flag = 0;
        tmp = mod_pow(a[i], q, n);
        if(tmp == 1) continue;

        for(int j=0; j<=k-1; j++) {
            if(tmp == n-1) {
                flag = 1;
                break;
            }
            tmp = mod_mul(tmp, tmp, n);
        }
        if(!flag) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    while(N--) {
        int a; cin >> a;
        bool prime = 0;
        
        for(int i=2; i<=a/2; i++) {
            int a1=i, a2=a-i;
            if(miller_rabin(a1) && miller_rabin(a2)) {
                cout << "Yes" << '\n';
                prime = 1;
                break;
            }
        }
        if(!prime) cout << "No" << '\n';
    }

    return 0;
}   