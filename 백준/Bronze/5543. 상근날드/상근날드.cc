#include <iostream>
using namespace std;

int main() {
    int a, b, c, x, y, min;
    cin >> a >> b >> c >> x >> y;
    if(x>=y) {
        a+=y;
        b+=y;
        c+=y;
    }
    else {
        a+=x;
        b+=x;
        c+=x;
    }
    if (a<=b && a<=c) cout << a-50 << '\n';
    else if (b<=a && b<=c) cout << b-50 << '\n';
    else cout << c-50;
}