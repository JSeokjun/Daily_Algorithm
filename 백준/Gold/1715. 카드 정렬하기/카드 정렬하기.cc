#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, a, sum, result=0;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<N; i++) {
        cin >> a;
        pq.push(a);
    }

    while(pq.size()!=1) {
        sum=0;
        sum+=pq.top();
        pq.pop();
        sum+=pq.top();
        pq.pop();
        pq.push(sum);
        result+=sum;
    }
    cout << result;
}