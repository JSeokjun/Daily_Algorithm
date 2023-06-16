#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, S, cnt=0;
    cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++) {
        cin >> S;
        if(find(v.begin(), v.end(), S) != v.end()) cnt++;
        v.push_back(S);
    }
    cout << cnt;
}