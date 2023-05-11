#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    int n;
    string str;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> n;
        cin >> str;
        for(int j=0; j<str.size(); j++) {
            if(j==n-1) continue;
            cout << str[j];
        }
        cout << '\n';
    }
}