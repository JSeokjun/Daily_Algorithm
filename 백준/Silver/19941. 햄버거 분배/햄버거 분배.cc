#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  string str; cin >> str;
  vector<char> V;
  int max_person = 0;

  for (int i=0; i<N; i++) {
    V.push_back(str[i]);
  }

  for (int i=0; i<N; i++) {
    if (V[i] == 'P') {
      for (int j=i-K; j<=i+K; j++) {
        if (j >= 0 && j < N && V[j] == 'H') {
          max_person++;
          V[j] = 'E';
          break;
        }
      }
    }
  }

  cout << max_person;
 
  return 0;
}