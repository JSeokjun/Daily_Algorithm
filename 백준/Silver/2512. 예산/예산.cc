#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  long long sum = 0;
  vector<int> V;

  for (int i=0; i<N; i++) {
    int request; cin >> request;
    sum += request;
    V.push_back(request);
  }

  sort(V.begin(), V.end());

  int M; cin >> M;
  int last_index = V.size() - 1;
  long long gap = 0;

  if (sum <= M) cout << V[last_index];
  else {
    int i = last_index;
    while (1) {
      gap += (V[i] - V[i-1]) * (last_index+1 - i);
      if (sum - gap > M) i--;
      else {
        cout << ((M - (sum - gap)) / (last_index+1 - i)) + V[i-1];
        break;
      }
    }
  }
 
  return 0;
}
