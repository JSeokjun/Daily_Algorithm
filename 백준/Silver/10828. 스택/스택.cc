#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, n;
    string C;
    stack<int> s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> C;
        if(C=="push") {
            cin >> n;
            s.push(n);
        }
        else if(C=="pop") {
            if(s.empty()) cout << -1 <<'\n';
            else {
                cout << s.top() <<'\n';
                s.pop();
            }
        }
        else if(C=="size") {
            cout << s.size() <<'\n';
        }
        else if(C=="empty") {
            if(s.empty()) cout << 1 <<'\n';
            else cout << 0 <<'\n';
        }
        else if(C=="top") {
            if(s.empty()) cout << -1 <<'\n';
            else {
                cout << s.top() <<'\n';
            }
        }
        else return -1;
    }
    return 0;
}