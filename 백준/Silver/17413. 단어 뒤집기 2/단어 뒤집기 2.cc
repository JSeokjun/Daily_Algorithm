#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    string str;
    vector<char> v;
    stack<char> s;
    getline(cin, str);
    for(int i=0; i<str.length();) {
        if(str[i]=='<') {
            while(!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            while(!(str[i]=='>')) {
                v.push_back(str[i]);
                i++;
            }
            v.push_back('>');
            i++;
        }
        else if(str[i]==' ') {
            while(!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            v.push_back(' ');
            i++;
        }
        else {
            s.push(str[i]);
            if(i==str.length()-1) {
                while(!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            i++;
        }
    }
    for(int i=0; i<v.size(); i++) {
        cout << v[i];
    }
}   