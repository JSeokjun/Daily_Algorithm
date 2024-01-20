#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str; cin >> str;
    int zero = 0, one = 0;
    char tmp = str[0];

    for(int i=1; i<str.size(); i++) {
        if(str[i] != tmp) {
            if(tmp == '0') zero++;
            else one++;
            tmp = str[i];
        }
    }

    if(tmp == '0') zero++;
    else one++;

    cout << min(zero, one);
}   