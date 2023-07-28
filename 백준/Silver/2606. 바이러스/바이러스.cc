#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int main() {
    int N, M, V=1, a, b, tmp=0;
    cin >> N >> M;
    vector<int> g[N+1];
    stack<int> st;
    set<int> s;

    for(int i=0; i<M; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    st.push(1);
    s.insert(1);

    while(1) {
        if(s.find(tmp)==s.end() && tmp!=0) {
            V = tmp;
            st.push(V);
            s.insert(st.top());    
        }
        if(g[V].size()==0) {
            st.pop();
            if(st.empty()) break;
            V=st.top();
            continue;   
        }
        tmp = g[V].back();
        g[V].pop_back();
    }

    cout << s.size()-1;
}