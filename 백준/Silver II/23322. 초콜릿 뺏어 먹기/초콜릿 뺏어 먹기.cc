#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    vector<int> V(N+1);
    set<int> S;
    int min=2001;

    for(int i=1; i<=N; i++) {
        int n; cin >> n;
        V[i] = n;
        if(n < min) min = n;
    }
    
    int max_sum=0, min_day=0;

    while(1) {
        for(int i=1; i<=N; i++) {
            S.insert(V[i]);
        }
        if(S.size() == 1) break;
        S.clear();
        
        for(int i=K+1; i<=N; i++) {
            if(V[i]>min && V[i-K]==min) {
                max_sum += V[i]-V[i-K];
                V[i] = V[i-K];
                break;
            }
        }

        min_day++;
        sort(V.begin(),V.end());
    }

    cout << max_sum << ' ' << min_day;

    return 0;
}   