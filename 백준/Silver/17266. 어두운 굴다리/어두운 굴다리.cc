#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> V;

  for (int i=0; i<M; i++) {
    int x; cin >> x;
    V.push_back(x);
  }

  int answer = 0;

  if (V[0] >= N - V.back()) answer = V[0];
  else answer = N - V.back();

  for (int i=0; i<M-1; i++) {
    int range = (V[i+1] - V[i]) / 2 + (V[i+1] - V[i]) % 2;
    if (range > answer) answer = range;
  }

  cout << answer;

  return 0;
}