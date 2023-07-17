#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, a, b, c, cnt=0;
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(int i=0; i<N; i++) {
        cin >> a >> b >> c;
        pq.push({b, c});
    }
    
    for(int i=0; i<N; i++) {
        if(pq2.empty()) {
            cnt++;
            pq2.push(pq.top().second);
            pq.pop();
            continue;
        }

        if((pq2.top()<=pq.top().first)) {
            pq2.push(pq.top().second);
            pq.pop();
            pq2.pop();
        }
        else {
            cnt++;
            pq2.push(pq.top().second);
            pq.pop();
        }
    }
    cout << cnt;
}