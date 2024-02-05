#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N; N--;
    int num = 13, sum = 26;

    while(N--) {
        num += sum;
        sum += 14;
    }    

    cout << num;

    return 0;
}   