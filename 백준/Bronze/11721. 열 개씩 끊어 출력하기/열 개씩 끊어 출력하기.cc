#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    int cnt = 0;
    cin >> w;
    
    for (int i=0; i<w.length(); i++) {
        cout << w[i];
        cnt++;
        if(cnt==10) {
            cout << '\n';
            cnt = 0;
        }
    }
}