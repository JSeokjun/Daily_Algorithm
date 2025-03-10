#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M; cin >> M;
  bool S[20], all_s[20], empty_s[20];
  for (int i=0; i<20; i++) S[i] = false;
  string act = "";
  int num = 0;

  for (int i=0; i<M; i++) {
    cin >> act;
    if (act != "all" && act != "empty") {
      cin >> num;
    }

    if (act == "add") {
      S[num-1] = true;
    }
    else if (act == "remove") {
      S[num-1] = false;
    }
    else if (act == "check") {
      cout << S[num-1] << '\n';
    }
    else if (act == "toggle") {
      S[num-1] ? S[num-1] = false : S[num-1] = true;
    }
    else if (act == "all") {
      for (int j=0; j<20; j++) S[j] = true;
    }
    else if (act == "empty") {
      for (int j=0; j<20; j++) S[j] = false;
    }
    else {
      return -1;
    }
  }

  return 0;
}