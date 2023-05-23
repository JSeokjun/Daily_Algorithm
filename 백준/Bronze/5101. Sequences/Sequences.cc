#include <iostream>
using namespace std;

int main() {
    int x, a, b, cnt;
    while(1) {
        cin >> x;
        cin >> a;
        cin >> b;
        if (x==0 && a==0 && b==0) break;
        cnt = 1;
        while(1) {
            if (x==b) {
                cout << cnt;
                cout << '\n';
                break;
            }

            x+=a;
            cnt++;
            
            if (a<0) {
                if (x<b) {
                    cout << 'X';
                    cout << '\n';
                    break;
                }
            }
            else if (a>0) {
                if (x>b) {
                    cout << 'X';
                    cout << '\n';
                    break;
                }
            }
            else {
                cout << 'X';
                cout << '\n';
                break;
            }
        }
    }
}