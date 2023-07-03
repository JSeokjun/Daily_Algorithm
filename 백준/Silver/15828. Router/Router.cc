#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, m;
    cin >> n;
    while(1) {
        cin >> m;
        if(m==-1) break;

        if(m==0) q.pop();
        else {
            if(q.size()==n) continue;
            else q.push(m);
        }
    }
    if(q.empty()) cout << "empty";
    else {
        while(!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }
}   