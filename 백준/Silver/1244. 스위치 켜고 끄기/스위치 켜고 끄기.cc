/*
# 코드 리뷰

## 전반적인 평가
코드는 전체적으로 문제의 요구사항을 잘 구현하고 있습니다. 하지만 몇 가지 개선할 수 있는 부분이 있습니다.

## 개선 사항
1. 자료형 문제: vector<bool>에 -1을 넣고 있는데, bool 타입은 true(1)와 false(0)만 저장할 수 있습니다. -1은 자동으로 true로 변환되지만, 의도를 명확히 하는 것이 좋습니다.
2. 인덱싱 방식: 0번 인덱스를 사용하지 않기 위해 -1을 넣는 방식은 이해할 수 있지만, 더 명확한 방법이 있습니다.
3. 여학생 로직: 여학생의 스위치 조작 로직에서 대칭을 확인하는 부분이 정확하지만, 코드를 더 명확하게 할 수 있습니다.

## 추가 제안
1. XOR 연산자 대신 논리 부정 연산자 사용: switch_arr[j*num] ^ 1 대신 !switch_arr[j*num]을 사용하면 더 직관적입니다.
2. 주석 추가: 코드의 각 부분이 무엇을 하는지 설명하는 주석을 추가하면 가독성이 향상됩니다.
3. 반복문 조건 개선: i<switch_len+1 대신 i<=switch_len을 사용하면 더 명확합니다.
4. 변수명 개선: 변수명을 더 명확하게 지정하면 코드 이해가 쉬워집니다. 예를 들어 cnt보다는 offset이 더 의미가 명확할 수 있습니다.
*/

/*
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int switch_len, student_num;
  vector<bool> switch_arr; 
  switch_arr.push_back(-1);

  cin >> switch_len;
  for (int i=0; i<switch_len; i++) {
    bool status; cin >> status;
    switch_arr.push_back(status);
  }
  cin >> student_num;

  for (int i=0; i<student_num; i++) {
    int gender, num;
    cin >> gender >> num;

    if (gender == 1) {
      for (int j=1; j*num<=switch_len; j++) {
        switch_arr[j*num] = switch_arr[j*num] ^ 1; 
      }
    }
    else if (gender == 2) {
      int cnt = 1;
      switch_arr[num] = switch_arr[num] ^ 1;

      while (num - cnt >= 1 && num + cnt <= switch_len) {
        if (switch_arr[num-cnt] == switch_arr[num+cnt]) {
          switch_arr[num-cnt] = switch_arr[num-cnt] ^ 1;
          switch_arr[num+cnt] = switch_arr[num+cnt] ^ 1;
          cnt++;
        }
        else {
          break;
        }
      }
    }
  }

  for (int i=1; i<switch_len+1; i++) {
    cout << switch_arr[i] << ' ';
    if (i % 20 == 0) cout << '\n';
  }

  return 0;
}
*/

// 개선된 코드
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int switch_len, student_num;
  vector<bool> switch_arr;
  
  // 1번 인덱스부터 시작하기 위해 0번 인덱스에 더미 값 추가
  switch_arr.push_back(false);  // -1 대신 false 사용

  // 스위치 상태 입력 받기
  cin >> switch_len;
  for (int i=0; i<switch_len; i++) {
    bool status; 
    cin >> status;
    switch_arr.push_back(status);
  }
  
  // 학생 수 입력 받기
  cin >> student_num;

  // 각 학생별 스위치 조작
  for (int i=0; i<student_num; i++) {
    int gender, num;
    cin >> gender >> num;

    if (gender == 1) {  // 남학생
      // 받은 수의 배수 위치에 있는 스위치 상태 변경
      for (int j=1; j*num<=switch_len; j++) {
        switch_arr[j*num] = !switch_arr[j*num];  // XOR 대신 논리 부정 사용
      }
    }
    else if (gender == 2) {  // 여학생
      // 자기 위치 스위치 상태 변경
      switch_arr[num] = !switch_arr[num];
      
      // 좌우 대칭 확인하며 스위치 상태 변경
      int offset = 1;  // cnt 대신 더 명확한 변수명 사용
      while (num - offset >= 1 && num + offset <= switch_len) {
        if (switch_arr[num-offset] == switch_arr[num+offset]) {
          switch_arr[num-offset] = !switch_arr[num-offset];
          switch_arr[num+offset] = !switch_arr[num+offset];
          offset++;
        }
        else {
          break;
        }
      }
    }
  }

  // 최종 스위치 상태 출력
  for (int i=1; i<=switch_len; i++) {  // 조건을 i<=switch_len으로 변경하여 명확하게
    cout << switch_arr[i] << ' ';
    if (i % 20 == 0) cout << '\n';  // 20개씩 출력
  }

  return 0;
}
