#include <iostream>
#include <stack>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string str; cin >> str;
    stack<char> S;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        
        if(ch>='A' && ch<='Z') cout << ch;

        else if(S.empty()) S.push(ch);

        else if(ch == ')') {
            while(S.top()!='(') {
                cout << S.top();
                S.pop();
            }
            S.pop();
        }
        
        else if(ch == '(') S.push(ch);

        else if(ch=='+' || ch=='-') {
            while(!S.empty() && (S.top()=='+' || S.top()=='-' || S.top()=='*' || S.top()=='/')) {
                cout << S.top();
                S.pop();
            }
            S.push(ch);
        }

        else if(ch=='*' || ch=='/') {
            while(!S.empty() && (S.top()=='*' || S.top()=='/')) {
                cout << S.top();
                S.pop();
            }
            S.push(ch);
        }
    }

    while(!S.empty()) {
        cout << S.top();
        S.pop();
    }

    return 0;
}