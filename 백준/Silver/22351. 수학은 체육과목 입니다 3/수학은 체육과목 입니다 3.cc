#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, str2;
    int a, b;
    bool bl = false;
    cin >> str;
    while(1) {
        if(bl) break;
        for(int i=1; i<=4; i++) {
            if(bl) break;
            for(int j=1; j<=4; j++) {
                str2="";
                if(i+j>str.length()) continue;
                a = stoi(str.substr(0,i));
                b = stoi(str.substr(str.length()-j));
                if(a<b && b<=2889) {
                    for(int i=a; i<=b; i++) {
                        str2 += to_string(i);
                    }
                    if(str==str2) {
                        cout << a << ' ' << b;
                        bl = true;
                        break;
                    }
                }
            }
        }
        if(!bl) {
            cout << str << ' ' << str;
            break;
        }
    }
}