#include <iostream>
#include <cmath>
using namespace std;

int main() {
  string s; cin >> s;

  long long int ans = 0;
  
  for (int i = 0; i < s.length(); i++) {
    ans += pow(s[i] - '0', 5);
  }
  cout << ans;

  return 0;
}