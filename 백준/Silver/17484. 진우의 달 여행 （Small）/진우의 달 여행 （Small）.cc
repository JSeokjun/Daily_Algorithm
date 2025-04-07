#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int matrix[N][M];
  queue<tuple<int,int,int,int>> Q;
  int min_gas = 600;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int gas; cin >> gas;
      matrix[i][j] = gas;
    }
  }

  for (int i=0; i<M; i++) {
    Q.push({0, i, matrix[0][i], 2});
  }

  while(!Q.empty()) {
    int x, y, g, l;
    x = get<0>(Q.front());
    y = get<1>(Q.front());
    g = get<2>(Q.front());
    l = get<3>(Q.front());
    Q.pop();

    for (int i=-1; i<=1; i++) {
      if (i == l) continue;
      if (i == -1 && y == 0) continue;
      if (i == 1 && y == M-1) continue;
      if (x+1 == N-1) {
        if (g+matrix[x+1][y+i] < min_gas) min_gas = g+matrix[x+1][y+i];
        continue;
      }

      Q.push({x+1, y+i, g+matrix[x+1][y+i], i});
    }
  }

  cout << min_gas;
 
  return 0;
}