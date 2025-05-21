#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    vector<long long> solutions(N);
    
    for (int i=0; i<N; i++) {
        cin >> solutions[i];
    }
    
    int left = 0;
    int right = N - 1;
    
    long long min_diff = 2000000000;
    long long a = 0, b = 0;
    
    while (left < right) {
        long long sum = solutions[left] + solutions[right];
        long long abs_sum = sum < 0 ? -sum : sum;
        
        if (abs_sum < min_diff) {
            min_diff = abs_sum;
            a = solutions[left];
            b = solutions[right];
        }
        
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << a << ' ' << b;
    
    return 0;
}