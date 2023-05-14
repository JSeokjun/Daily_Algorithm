#include <iostream>
#include <string>
using namespace std;

int main() {
    string j, d;
    cin >> j;
    cin >> d;
    if (j.length() >= d.length()) cout << "go";
    else cout << "no";
}