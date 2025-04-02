#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M; cin >> N >> M;
  vector<pair<string,int>> V;
  map<string, int> map;

  for (int i = 0; i < N; i++) {
    string word; cin >> word;

    if (word.length() >= M) {
      if (map.find(word) != map.end()) {
        map[word] += 1;
      }
      else {
        map.insert({word, 1});
      }
    }
  }

  for (auto it = map.begin(); it != map.end(); ++it) {
    V.push_back({it->first, it->second});
  }

  sort(V.begin(), V.end(), [](const auto& a, const auto& b) {
    if (a.second != b.second) {
      return a.second > b.second;
    }
    if (a.first.length() != b.first.length()) {
      return a.first.length() > b.first.length();
    }
    return a.first < b.first;
  });

  for (int i = 0; i < map.size(); i++) {
    cout << V[i].first << '\n';
  }
 
  return 0;
}