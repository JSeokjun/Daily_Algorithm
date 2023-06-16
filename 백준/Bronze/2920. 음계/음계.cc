#include <iostream>
using namespace std;

int main() {
    int M, tmp, cnt=0;
    cin >> M;
    if(M==1) {
        for(int i=0; i<7; i++) {
            cin >> tmp;
            if(M+1==tmp) {
                M=tmp;
                cnt++;
                continue;
            }
            else {
                cout << "mixed";
                break;
            }
        }
        if(cnt==7) cout <<"ascending";
    }
    else if(M==8) {
        for(int i=0; i<7; i++) {
            cin >> tmp;
            if(M-1==tmp) {
                M=tmp;
                cnt++;
                continue;
            }
            else {
                cout << "mixed";
                break;
            }
        }
        if(cnt==7) cout <<"descending";
    }
    else cout << "mixed";
}