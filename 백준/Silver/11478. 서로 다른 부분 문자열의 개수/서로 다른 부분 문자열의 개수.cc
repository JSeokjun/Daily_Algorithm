#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;
    set<string> s;
    for(int i=0; i<=S.length()-1; i++) {
        for(int j=1; j<=S.length()-i; j++) {
            s.insert(S.substr(i,j));
        }
    }
    cout << s.size();
}