#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> q;
    for(int i=1; i<=N; i++) {
        q.push(i);
    }
    while(1) {
        if(q.size()==1) {
            cout << q.front();
            return 0;
        }
        q.pop();
        if(q.size()==1) {
            cout << q.front();
            return 0;
        }
        q.push(q.front());
        q.pop();
    }
}