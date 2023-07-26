#include <iostream>
#include <set>
using namespace std;

int main() {
    int a, b, n;
    set<int> s;
    cin >> a >> b;
    for(int i=0; i<a+b; i++) {
        cin >> n;
        s.insert(n);
    }
    cout << (a+b)-(a+b-s.size())*2;
}