#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, a, b, cnt=0;
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        pq.push({a, b});
    }

    for(int i=0; i<N; i++) {
        if(i==0 || pq2.top()>pq.top().first){
            cnt++;
            pq2.push(pq.top().second);
            pq.pop();
        }
        else {
            pq2.push(pq.top().second);
            pq.pop();
            pq2.pop();
        }
    }

    cout << cnt;
    return 0;
}