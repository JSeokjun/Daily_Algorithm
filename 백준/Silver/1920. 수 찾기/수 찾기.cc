#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int tmp;
    set<int> A;

    for(int i=1; i<=N; i++) {
        cin >> tmp;
        A.insert(tmp);
    }

    int M; cin >> M;

    for(int i=1; i<=M; i++) {
        cin >> tmp;
        auto it = A.find(tmp);
        if(it!=A.end()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}