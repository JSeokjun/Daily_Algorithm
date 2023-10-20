#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    int max_sum = s1+s2+s3+1; 
    int arr[max_sum];
    for(int i=0; i<max_sum; i++) arr[i] = 0;
    
    for(int i=1; i<=s1; i++) {
        for(int j=1; j<=s2; j++) {
            for(int k=1; k<=s3; k++) {
                arr[i+j+k]++;
            }
        }
    }

    int mode=0, result=0;
    for(int i=max_sum-1; i>=3; i--) {
        if(arr[i] >= mode) {
            mode = arr[i];
            result = i;
        } 
    }
    cout << result;

    return 0;
}   