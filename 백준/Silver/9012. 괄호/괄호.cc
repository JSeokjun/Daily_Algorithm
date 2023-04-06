#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    stack<int> stack;
    string str;
    cin >> str;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] == '(')
        stack.push(1);
      else {
        if (stack.empty()) {
          stack.push(1);
          break;
        }
        stack.pop();
      }
    }
    if (stack.empty())
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}