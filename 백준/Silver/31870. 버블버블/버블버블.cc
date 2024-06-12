#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> V1;
    vector<int> V2;
    int r1=0, r2=0;

    for(int i=1; i<=N; i++) {
        int tmp; cin >> tmp;
        V1.push_back(tmp);
        V2.push_back(tmp);
    }
    reverse(V1.begin(),V1.end());
    r1++;

    for(int i=0; i<N-1; i++) {
        for(int j=0; j<N-1-i; j++) {
            if(V1[j]>V1[j+1]) {
                int tmp = V1[j];
                V1[j] = V1[j+1];
                V1[j+1] = tmp;
                r1++;
            }
        }
    }

    for(int i=0; i<N-1; i++) {
        for(int j=0; j<N-1-i; j++) {
            if(V2[j]>V2[j+1]) {
                int tmp = V2[j];
                V2[j] = V2[j+1];
                V2[j+1] = tmp;
                r2++;
            }
        }
    }
    if(r1>=r2) cout << r2;
    else cout << r1;
}