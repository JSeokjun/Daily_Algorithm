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
        map[word]++; // 더 간결한 방식으로 빈도수 증가
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

  for (int i = 0; i < V.size(); i++) { // map.size() 대신 V.size() 사용
    cout << V[i].first << '\n';
  }
 
  return 0;
}