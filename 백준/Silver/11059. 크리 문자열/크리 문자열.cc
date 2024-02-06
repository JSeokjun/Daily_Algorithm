#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string str; cin >> str;
    int len = str.size();

    if(len%2) len--;  

    for(int i=len; i>=2; i-=2) {
        for(int j=0; j<=str.size()-i; j++) {
            int a = 0, b = 0, cnt = 0;

            for(int k=j; k<i+j; k++) {
                cnt++;
            
                if(cnt > i/2) b += str[k]-'0';
                else a += str[k]-'0';
            }
            if(a == b) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}   