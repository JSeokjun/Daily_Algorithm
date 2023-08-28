#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, P, sum=0, result=0;
    vector<int> v;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> P;
        v.push_back(P);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; i++) {
        sum += v[i];
        result += sum;    
    }
    cout << result;
}