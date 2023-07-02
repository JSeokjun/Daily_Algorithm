#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    bool b;
    int size;
    stack<int> s;
    while(1) {
        b=false;
        getline(cin, str);
        if(str==".") break;
        for(int i=0; i<str.length()-1; i++) {
            if(str[i]=='(') s.push(0);
            else if(str[i]=='[') s.push(1);
            else if(str[i]==')') {
                if(s.empty()||s.top()==1) {
                    b=true;
                    break;
                }
                s.pop();
            }
            else if(str[i]==']') {
                if(s.empty()||s.top()==0) {
                    b=true;
                    break;
                }
                s.pop();
            }
        }
        if(b || !s.empty()) {
            cout << "no" << '\n';
            size = s.size();
            for(int i=0; i<size; i++) {
                s.pop();
            }
        } 
        else cout << "yes" << '\n';
    }
}