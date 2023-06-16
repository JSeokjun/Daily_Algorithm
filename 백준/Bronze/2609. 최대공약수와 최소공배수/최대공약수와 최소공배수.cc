#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << '\n';
    cout << lcm(n, m);
}