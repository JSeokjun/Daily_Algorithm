#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> cnt(201, 0);
  vector<int> fifth(201, 0);
  vector<int> score(201, 0);
  vector<int> table;
  vector<int> cnt_tmp(201, 0);
  int T; cin >> T;

  while (T--) {
    int N; cin >> N;

    for (int i=1; i<=N; i++) {
      int M; cin >> M;
      table.push_back(M);
      cnt[M]++;
      if (cnt[M] == 5) fifth[M] = i;
    }

    int score_cnt = 1;

    for (int i=0; i<N; i++) {
      cnt_tmp[table[i]]++;
      if (cnt[table[i]] == 6) {
        if (cnt_tmp[table[i]] <= 4) {
          score[table[i]] += score_cnt;
        }
        score_cnt++;
      }
    }

    int min_score = 1000;
    int win_team = 0;

    for (int i=1; i<=200; i++) {
      if (cnt[i] == 6) {
        if (score[i] < min_score || score[i] == min_score && fifth[i] < fifth[win_team]) {
          min_score = score[i];
          win_team = i;
        }
      }
    }

    for (int i=1; i<=200; i++) {
      cnt[i] = 0;
      fifth[i] = 0;
      score[i] = 0;
      cnt_tmp[i] = 0;
    }
    table.clear();

    cout << win_team << '\n';
  }

  return 0;
}