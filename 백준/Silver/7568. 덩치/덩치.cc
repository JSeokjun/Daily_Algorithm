#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  vector<tuple<int,int,int>> V;  
  int X, Y, rank = 1;

  for(int i=0; i<N; i++) {
    cin >> X >> Y;
    V.push_back(make_tuple(X, Y, 0));
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(i!=j && (get<0>(V[i]) < get<0>(V[j]) && get<1>(V[i]) < get<1>(V[j]))) rank++;
    }
    cout << rank << ' ';
    rank = 1;
  }

  return 0;
}