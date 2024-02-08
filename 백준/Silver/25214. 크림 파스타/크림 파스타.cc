#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, min, max=0; cin >> N >> min; N--;
    vector<int> V;
    V.push_back(0);

    while(N--) {
        int a; cin >> a;

        if(a-min > max) max = a-min;
        V.push_back(max);

        if(a < min) min = a;
    }

    for(int i=0; i<V.size(); i++) {
        cout << V[i] << ' ';
    }

    return 0;
}   