#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;
  cout << a * (b % 10) << '\n';
  cout << a * (int)((b % 100) * 0.1) << '\n';
  cout << a * (int)(b * 0.01) << '\n';
  cout << a * b;
}