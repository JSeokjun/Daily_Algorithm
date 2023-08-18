#include <iostream>
#include <map>
#include <stack>
using namespace std;

map<char, pair<char,char>> m;
bool v[26];

void dfs(int x) {
    char a = x+65, b = m[a].first, c = m[a].second;
    v[x] = 1;
    cout << a;

    if(b!='.') dfs(b-65);
    if(c!='.') dfs(c-65);
}

int main() {
    int N;
    char a, b, c;
    stack<char> s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a >> b >> c;
        m.insert({a, make_pair(b,c)}); 
    }

    // preorder traversal
    for(int i=0; i<N; i++) {
        if(!v[i]) dfs(i);
    }
    for(int i=0; i<N; i++) v[i]=0;
    cout << '\n';

    // inorder traversal
    s.push('A');
    v[0] = 1;
    while(!s.empty()) {
        char a = s.top(), b = m[a].first, c = m[a].second;
        
        if(!v[b-65] && b!='.') {
            s.push(b);
            v[b-65] = 1;
            continue;
        }
        cout << s.top();
        s.pop();
        
        if(!v[c-65] && c!='.') {
            s.push(c);
            v[c-65] = 1;
        }
    }
    for(int i=0; i<N; i++) v[i]=0;
    cout << '\n';

    // postorder traversal
    s.push('A');
    v[0] = 1;
    while(!s.empty()) {
        char a = s.top(), b = m[a].first, c = m[a].second;
        
        if(!v[b-65] && b!='.') {
            s.push(b);
            v[b-65] = 1;
        }
        else if(!v[c-65] && c!='.') {
            s.push(c);
            v[c-65] = 1;
        }
        else {
            cout << s.top();
            s.pop();
        }
    }
}