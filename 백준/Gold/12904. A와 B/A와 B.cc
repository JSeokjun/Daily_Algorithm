#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    for(int i=T.length()-1; i>=S.length(); i--) {
        if(T[i]=='A') {
            T.pop_back();
        }
        else if(T[i]=='B') {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
        else return -1;
    }
    if(S==T) cout << 1;
    else cout << 0;

    return 0;
}