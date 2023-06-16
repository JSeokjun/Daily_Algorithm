#include <iostream>
using namespace std;

void hi(int n) {
    for(int i=1; i<=n; i++) {
        cout << "Hello World, Judge " << i << '!' << '\n';
    }
}
int main() {
    int N;
    cin >> N;
    hi(N);
}