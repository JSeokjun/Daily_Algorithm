#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, tmp, max=1;
    cin >> N;
    vector<int> v(N+1,0);
    for(int i=0; i<N; i++) {
        cin >> tmp;
        v[tmp]++;
    }
    tmp = v[1];
    for(int i=2; i<=N; i++) {
        if(v[i]>tmp) {
            tmp=v[i];
            max=i;
        }
    }
    for(int i=1; i<=N; i++) {
        if(i!=max && v[i]==tmp) {
            cout << "skipped";
            return 0;
        }
    }
    cout << max;
    return 0;
}   