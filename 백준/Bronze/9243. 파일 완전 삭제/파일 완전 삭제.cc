#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    bool b = true;
    string x, y;
    cin >> n >> x >> y;
    if (n%2==0) {
        if (x==y) cout << "Deletion succeeded";
        else cout << "Deletion failed";
    }
    else {
        for (int i=0; i<x.length(); i++) {
            if (x[i] == y[i]) {
                cout << "Deletion failed";
                b = false;
                break; 
            }
        }
        if (b == true) cout << "Deletion succeeded";
    }
}