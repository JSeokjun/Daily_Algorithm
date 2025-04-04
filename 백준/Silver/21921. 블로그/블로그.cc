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

  // for (int i=0; i<N; i++) {
  //   cnt_visitor += V[i];

  //   if (i == X-1) {
  //     max_visitor = cnt_visitor;
  //   }
  //   else if (i > X-1) {
  //     cnt_visitor -= V[i-X];
  //   }
  //   else continue;

  //   if (cnt_visitor > max_visitor) {
  //     max_visitor = cnt_visitor;
  //     num_range = 1;
  //   }
  //   else if (cnt_visitor == max_visitor) {
  //     num_range++;
  //   }
  // }

  // 첫 X일 동안의 방문자 수 계산
  for (int i=0; i<X; i++) {
    cnt_visitor += V[i];
  }
  
  max_visitor = cnt_visitor;
  num_range = 1;

  // 슬라이딩 윈도우로 나머지 기간 확인
  for (int i=X; i<N; i++) {
    cnt_visitor += V[i] - V[i-X];  // 새 날짜 추가, 오래된 날짜 제거
    
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

// 개선 사항

// 1. 슬라이딩 윈도우 알고리즘을 더 명확하게 구현:
// 먼저 첫 X일 동안의 방문자 수를 계산
// 이를 초기 최대값으로 설정
// 이후 윈도우를 한 칸씩 이동하며 최대값 갱신

// 2. 코드 가독성 향상:
// 불필요한 조건문 제거
// 로직을 더 명확하게 분리