#include <iostream>
#include <set>
using namespace std;

int main() {
    string str;
    set<string> s;
    cin >> str;

    for(int i=0; i<str.length(); i++) {
        s.insert(str.substr(i));
    }
    for(set<string>::iterator it=s.begin(); it!=s.end(); it++) {
        cout << *it << '\n';
    }
}