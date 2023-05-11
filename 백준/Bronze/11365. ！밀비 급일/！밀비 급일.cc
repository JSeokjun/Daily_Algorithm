#include <iostream>
#include <string>
using namespace std;

int main() {
  string k;
  while (1) {
    getline(cin, k);
    if (k == "END")
      break;
    for (int i = k.size() - 1; i >= 0; i--)
      cout << k[i];
    cout << '\n';
  }
}