#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> chicken;
    int N, K, tmp; 
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        chicken.push_back(tmp);
    }
    cin >> K;
    
    for(int i=0; i<N; i+=N/K) {
        sort(chicken.begin()+i, chicken.begin()+i+N/K);
    }
    for(int i=0; i<N; i++) {
        cout << chicken[i] << ' ';
    }

    return 0;
}   