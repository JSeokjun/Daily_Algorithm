#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str; cin >> str;
    stack<int> S;
    bool state = 1;
    int result = 0;

    for(int i=0; i<str.size(); i++) {
        char tmp = str[i];
        
        if(tmp == '(') {
            S.push(1);
            state = 1;
        }
        else {
            S.pop();
            if(state) result += S.size(); 
            else result++;
            state = 0;
        }
    }

    cout << result;

    return 0;
}