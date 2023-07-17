#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, K, a;
    long sum, result;
    cin >> T;
    priority_queue<long, vector<long>, greater<long>> pq;

    for(int i=0; i<T; i++) {
        cin >> K;
        result=0;
        while(!pq.empty()) pq.pop();

        for(int i=0; i<K; i++) {
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
        cout << result << '\n';
    }
}