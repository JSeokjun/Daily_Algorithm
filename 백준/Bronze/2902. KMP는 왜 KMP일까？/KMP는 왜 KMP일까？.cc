#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i=0; i<str.length(); i++) {
        if(i==0) cout << str[i];
        else if(str[i]=='-') cout << str[i+1];
    }
}