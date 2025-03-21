#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string str; cin >> str;
  string bomb; cin >> bomb;

  int bomb_len = bomb.length();

  vector<char> V;

  for (int i=0; i<str.length(); i++) {
    V.push_back(str[i]);

    if (V.size() >= bomb_len) {
      bool is_bomb = true;

      for (int i = 0; i < bomb_len; i++) {
        if (V[V.size() - bomb_len + i] != bomb[i]) {
            is_bomb = false;
            break;
        }
      }

      if (is_bomb) {
        for (int i = 0; i < bomb_len; i++) {
            V.pop_back();
        }
      }
    }
  }

  if (V.empty()) {
      cout << "FRULA";
  } else {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i];
    }
  }

  return 0;
}