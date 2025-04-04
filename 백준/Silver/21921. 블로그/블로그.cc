#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, X; cin >> N >> X;
  vector<int> V;
  int max_visitor = 0, cnt_visitor = 0, num_range = 0;
  bool all_zero = true;

  for (int i=0; i<N; i++) {
    int visitor; cin >> visitor;
    V.push_back(visitor);

    if (visitor != 0) all_zero = false;
  }

  if (all_zero) {
    cout << "SAD";
    return 0;
  }

  for (int i=0; i<N; i++) {
    cnt_visitor += V[i];

    if (i == X-1) {
      max_visitor = cnt_visitor;
    }
    else if (i > X-1) {
      cnt_visitor -= V[i-X];
    }
    else continue;

    if (cnt_visitor > max_visitor) {
      max_visitor = cnt_visitor;
      num_range = 1;
    }
    else if (cnt_visitor == max_visitor) {
      num_range++;
    }
  }

  cout << max_visitor << '\n' << num_range;
 
  return 0;
}