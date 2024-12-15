#include <iostream>
#include <vector>

using namespace std;
int main(){
    int N; cin >> N;
    vector<long long> V(N, 0);

    for(int i=0; i<N; i++) {
        int M; cin >> M;

        if (i == 0) {
            if (M == 0) {
                V[i] = -1;
            }
            else {
                V[i] = 1;
            }
        }
        else {
            if (M == 0) {
                V[i] = V[i-1] - 1;
            }       
            else {
                V[i] = V[i-1] + 1;
            }
        }
    }

    long long sum = 0;
    for(int i=0; i<N; i++) {
        sum += V[i];
    }

    cout << sum;

    return 0;
}