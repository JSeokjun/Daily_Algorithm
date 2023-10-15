#include <iostream>
using namespace std;

int r, c;
int cnt = 0;
bool check = 0;

void Z(int p, int a, int b) {
    if(p==2) {
        for(int i=a; i<a+2; i++) {
            for(int j=b; j<b+2; j++) {
                if(i==r && j==c) {
                    check = 1;
                    break;
                }
                cnt++;
            }
            if(check) break;
        }
    }
    else {
        int d = p/2;
        if(!check) {
            if(r>=a && r<a+d && c>=b && c<b+d) Z(d, a, b);
            else cnt+=d*d;
        }
        if(!check) {
            if(r>=a && r<a+d && c>=b+d && c<b+d+d) Z(d, a, b+d);
            else cnt+=d*d;
        }
        if(!check) {
            if(r>=a+d && r<a+d+d && c>=b && c<b+d) Z(d, a+d, b);
            else cnt+=d*d;
        }
        if(!check) {
            if(r>=a+d && r<a+d+d && c>=b+d && c<b+d+d) Z(d, a+d, b+d);
            else cnt+=d*d;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; 
    cin >> N >> r >> c;

    int p = 1;
    for(int i=0; i<N; i++) p*=2;

    Z(p, 0, 0);
    cout << cnt;

    return 0;
}   