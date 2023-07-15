#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, a;
    long sum;
    cin >> n >> m;
    priority_queue<long, vector<long>, greater<long>> pq;

    for(int i=0; i<n; i++) {
        cin >> a;
        pq.push(a);
    }
    for(int i=0; i<m; i++) {
        sum = 0;
        sum += pq.top();
        pq.pop();
        sum += pq.top(); 
        pq.pop();
        pq.push(sum);
        pq.push(sum);
    }
    sum = 0;
    for(int i=0; i<n; i++) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}