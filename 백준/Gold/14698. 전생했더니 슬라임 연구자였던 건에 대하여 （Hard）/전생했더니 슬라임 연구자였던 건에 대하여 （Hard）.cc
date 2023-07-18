#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    long long a, sum, result;
    cin >> T;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=0; i<T; i++) {
        cin >> N;
        result=1;
        while(!pq.empty()) pq.pop();

        for(int i=0; i<N; i++) {
            cin >> a;
            pq.push(a);
        }

        if(N==1) {
            cout << 1 << '\n';
            continue;
        }

        while(pq.size()!=1) {
            sum=0;
            sum+=pq.top();
            pq.pop();
            sum*=pq.top();
            pq.pop();
            pq.push(sum);
            result*=(sum%1000000007);
            result%=1000000007;
        }
        cout << result%1000000007 << '\n';
    }
}