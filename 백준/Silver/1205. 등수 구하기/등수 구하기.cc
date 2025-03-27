#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, new_score, P; cin >> N >> new_score >> P;

  if (N == 0) {
    cout << 1;
    return 0;
  }

  vector<pair<int,int>> V;
  int rank = 1, score = 0;
  cin >> score;

  V.push_back({score, rank});

  if (N == 1) {
    if (V[0].first <= new_score) {
      cout << V[0].second;
      return 0;
    }
    else {
      cout << V[0].second + 1;
      return 0;
    }
  }

  for (int i=1; i<N; i++) {
    cin >> score;
    if (V[i-1].first == score) {
      V.push_back({score, rank});
    }
    else {
      rank = i+1;
      V.push_back({score, rank});
    }
  }

  for (int i=0; i<N; i++) {
    if ((V[i].first < new_score) || ((V[i].first != V.back().first || N < P) && V[i].first == new_score)) {
      cout << V[i].second;
      return 0;
    }
  }

  if (N < P) {
    cout << V.size() + 1;
  }
  else {
    cout << -1;
  }

  return 0;
}