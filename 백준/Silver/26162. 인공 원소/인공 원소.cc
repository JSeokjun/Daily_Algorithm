#include <iostream>
#include <math.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;

    while(N--) {
        int a; cin >> a;
        bool prime;

        if(a==1 || a==2 || a==3) {
            cout << "No" << '\n';
            continue;
        }
        for(int i=2; i<=a/2; i++) {
            int a1=i, a2=a-i;
            prime = 1;
             
            for(int j=2; j<=sqrt(a1)+1; j++) {
                if(a1%j==0 && a1!=2) {
                    prime = 0;
                    break;
                }   
            }
            if(prime) {
                for(int j=2; j<=sqrt(a2)+1; j++) {
                    if(a2%j==0 && a2!=2) {
                        prime = 0;
                        break;
                    }
                }
            }
            if(prime) {
                cout << "Yes" << '\n';
                break;
            }
        }
        if(!prime) cout << "No" << '\n'; 
    }

    return 0;
}   