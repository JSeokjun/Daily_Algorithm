#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double n;
    cin >> n;
    if(n==0) cout << 0;
    else {
        vector<int> v;
        int exc = round(n*0.15);
        int sum=0, op;

        for(int i=0; i<n; i++) {
            cin >> op;
            v.push_back(op);
        }
        sort(v.begin(), v.end());

        for(int i=exc; i<n-exc; i++) {
            sum += v[i]; 
        }
        cout << round(sum/(n-2*exc));
    }
}