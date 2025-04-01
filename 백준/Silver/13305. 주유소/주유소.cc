#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<long,long>> V;

  for (int i=0; i<N-1; i++) {
    int distance; cin >> distance;
    V.push_back({0,distance});
  }
  V.push_back({0,0});

  for (int i=0; i<N; i++) {
    int price; cin >> price;
    V[i].first = price;
  }

  int index = 0;
  long long cost = 0;

  while(1) {
    bool is_break = false; 

    for (int j=index; j<N-1; j++) {
      if (V[index].first <= V[j].first) {
        cost += V[index].first * V[j].second;
      }
      else {
        index = j;
        is_break = true;
        break;
      }
    }
    if (!is_break) break;
  }

  cout << cost;

  return 0;
}