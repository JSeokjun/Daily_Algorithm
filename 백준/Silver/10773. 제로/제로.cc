#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K, N, sum=0;
    cin >> K;
    stack<int> s;
    for(int i=0; i<K; i++) {
        cin >> N;
        if(N==0) s.pop();
        else s.push(N); 
    }
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}