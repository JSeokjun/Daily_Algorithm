#include <iostream>

using namespace std;

int main() {
  int a = 0, b = 0, c = 0;

  while(1) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    } else if ((a >= b && a >= c && a >= b+c) || (b >= a && b >= c && b >= a+c) || (c >= b && c >= a && c >= b+a)) {
      cout << "Invalid" << "\n";
    } else if (a == b && b == c) {
      cout << "Equilateral" << "\n";
    } else if ((a == b && b != c) || (a == c && b != c) || (b == c && c != a)) {
      cout << "Isosceles" << "\n";
    } else if (a != b && b != c && c != a) {
      cout << "Scalene" << "\n";
    } 
  }

  return 0;
}
