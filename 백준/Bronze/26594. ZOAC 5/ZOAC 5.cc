#include <iostream>
using namespace std;

int main() {
    string str;
    int cnt=0;
    char tmp;
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(i!=0 && tmp!=str[i]) break;
        tmp = str[i];
        cnt++;
    }
    cout << cnt;
}