#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    
    while (T--) {
        int N; cin >> N;
        vector<int> prices(N);
        
        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }
        
        long long profit = 0;
        int max_price = prices[N-1];

        for (int i=N-1; i>=0; i--) {
            if (prices[i] >= max_price) {
                max_price = prices[i];
            } 
            else {
                profit += (max_price - prices[i]);
            }
        }

        cout << profit << '\n';
    }
    
    return 0;
}