#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, x;
    cin >> N;
    priority_queue<int> pq;
    
    for(int i=0; i<N; i++) {
        cin >> x;
        
        if(x==0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
}