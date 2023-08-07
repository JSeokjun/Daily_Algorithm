#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    int N, K, sec;
    cin >> N >> K;

    set<int> s;
    queue<pair<int, int>> q;
    s.insert(N);
    q.push(make_pair(N, 0));
    
    while(1) {
        N = q.front().first;
        sec = q.front().second;

        if(N==K) {
            cout << sec;
            return 0;
        }
        q.pop();

        if(s.find(N-1)==s.end()) if(N>=0) {
            q.push(make_pair(N-1, sec+1));
            s.insert(N-1);
        }
        if(s.find(N+1)==s.end()) if(N+1<2*K) {
            q.push(make_pair(N+1, sec+1));
            s.insert(N+1);
        }
        if(s.find(2*N)==s.end()) if(2*N<2*K) {
            q.push(make_pair(2*N, sec+1));
            s.insert(2*N);
        }
    } 
}