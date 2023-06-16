#include <iostream>
using namespace std;

int main() {
    int n, op, c=0, nc=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> op;
        if(op==1) c++;
        else nc++;
    }
    if(c>nc) cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";
}