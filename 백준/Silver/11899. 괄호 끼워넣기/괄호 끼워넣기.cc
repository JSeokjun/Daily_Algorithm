#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    while(!(str.find("()")==string::npos)) {
        str.erase(str.find("()"), 2);
    }
    cout << str.length();
}   