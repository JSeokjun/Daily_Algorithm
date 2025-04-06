#include <iostream>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  string str; cin >> str;
  int max_person = 0;

  for (int i=0; i<N; i++) {
    if (str[i] == 'P') {
      for (int j=i-K; j<=i+K; j++) {
        if (j >= 0 && j < N && str[j] == 'H') {
          max_person++;
          str[j] = 'E';
          break;
        }
      }
    }
  }

  cout << max_person;
 
  return 0;
}

// 개선 가능한 부분
// 불필요한 벡터 변환: 문자열 str을 벡터 V로 변환하는 과정이 불필요합니다. 문자열을 직접 사용해도 됩니다.
