#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    bool enter[200001]{0};
    int a, b, result = 0;

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        if(enter[a] != b) enter[a] = b;
        else result++;
    }

    for(int i=1; i<=200000; i++) {
        if(enter[i] == 1) result++; 
    }

    cout << result;

    return 0;
}