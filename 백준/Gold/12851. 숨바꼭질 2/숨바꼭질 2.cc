#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N, K, sec;
    cin >> N >> K;

    vector<int> v;
    set<int> s;
    queue<pair<int, int>> q;
    s.insert(N);
    q.push(make_pair(N, 0));
    
    while(1) {
        N = q.front().first;
        sec = q.front().second;
        s.insert(N);

        if(!v.empty()) if(sec>v[0]) break;

        if(N==K) v.push_back(sec);

        q.pop();

        if(s.find(N-1)==s.end()) if(N>=0) q.push(make_pair(N-1, sec+1));
        if(s.find(N+1)==s.end()) if(N+1<2*K) q.push(make_pair(N+1, sec+1));
        if(s.find(2*N)==s.end()) if(2*N<2*K) q.push(make_pair(2*N, sec+1));
    }

    cout << v[0] << '\n' << v.size();
}