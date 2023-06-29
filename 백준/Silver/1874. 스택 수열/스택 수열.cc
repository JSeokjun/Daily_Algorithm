#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m, idx=0;
    bool b = true;
    stack<int> s;
    vector<int> v1;
    vector<char> v2;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> m;
        v1.push_back(m);
    }
    int i=1;
    while(1) {
        if(s.empty()) {
            if(i>n) break;
            s.push(i);
            i++;
            v2.push_back('+');
        }
        else if(s.top()==v1[idx]) {
            s.pop();
            v2.push_back('-');
            idx++;
        }
        else {
            if(i>n) break;
            s.push(i);
            i++;
            v2.push_back('+');
        }
    }
    if(s.empty()) {
        for(int i=0; i<v2.size(); i++) {
            cout << v2[i] << '\n';
        }
    }
    else cout << "NO";
}