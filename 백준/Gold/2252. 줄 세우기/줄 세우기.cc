#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M, A, B;
    cin >> N >> M;
    int arr[N+1];
    vector<int> v1[N+1], v2[N+1];
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        v1[B].push_back(A);
        v2[A].push_back(B);
    }
    for(int i=1; i<=N; i++) {
        arr[i] = v1[i].size();
    }
    queue<int> q;
    bool b;
    while(1) {
        b = 0;
        for(int i=1; i<=N; i++) {
            if(arr[i]==0) {
                q.push(i);
                b = 1;
            }
        }
        if(!b) break;
        while(!q.empty()) {
            int n = q.front();
            for(int i=0; i<v2[n].size(); i++) {
                arr[v2[n][i]]--;
            }
            arr[n]--; 
            q.pop();
            cout << n << ' ';
        }
    }
}