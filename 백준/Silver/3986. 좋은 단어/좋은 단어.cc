#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, cnt=0;
    string str;
    cin >> N;
    for(int i=0; i<N; i++) {
        stack<char> s;
        cin >> str;
        for(int j=0; j<str.length(); j++) {
            if(!s.empty() && s.top()==str[j]) s.pop();
            else s.push(str[j]);
        }
        if(s.empty()) cnt++;   
    }
    cout << cnt;
}