#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    if(n%2==0) {
        if((n/4)%2==0) cout << 2;
        else cout << 4;
    }
    else {
        if(n%8==1) cout << 1;
        else if(n%8==5) cout << 5;
        else cout << 3;
    }
}