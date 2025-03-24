#include <iostream>
#include <set>

using namespace std;

int main() {

  int N; cin >> N;
  char game; cin >> game;
  set<string> S;

  while (N--) {
    string name; cin >> name;
    S.insert(name);
  }

  if (game == 'Y') {
    cout << S.size();
  }
  else if (game == 'F') {
    if (S.size() < 2) cout << 0;
    else cout << S.size() / 2;
  }
  else if (game == 'O') {
    if (S.size() < 3) cout << 0;
    else cout << S.size() / 3;
  }

  return 0;
}