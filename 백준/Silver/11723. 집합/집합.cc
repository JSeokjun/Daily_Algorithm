// #include <iostream>

// using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int M; cin >> M;
//   bool S[20]; for (int i=0; i<20; i++) S[i] = false;
//   string act = "";
//   int num = 0;

//   for (int i=0; i<M; i++) {
//     cin >> act;
//     if (act != "all" && act != "empty") {
//       cin >> num;
//     }

//     if (act == "add") {
//       S[num-1] = true;
//     }
//     else if (act == "remove") {
//       S[num-1] = false;
//     }
//     else if (act == "check") {
//       cout << S[num-1] << '\n';
//     }
//     else if (act == "toggle") {
//       S[num-1] ? S[num-1] = false : S[num-1] = true;
//     }
//     else if (act == "all") {
//       for (int j=0; j<20; j++) S[j] = true;
//     }
//     else if (act == "empty") {
//       for (int j=0; j<20; j++) S[j] = false;
//     }
//     else {
//       return -1;
//     }
//   }

//   return 0;
// }

/* 비트 마스킹 활용 버전 */
/* 이 문제는 비트 마스킹을 사용하면 더 효율적으로 구현할 수 있습니다. 20개의 요소를 가진 집합은 하나의 정수(int)로 표현 가능합니다. */
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M; cin >> M;
  int S = 0; // 비트마스크로 집합 표현
  string act;
  int num;

  for (int i=0; i<M; i++) {
    cin >> act;
    if (act != "all" && act != "empty") {
      cin >> num;
    }

    if (act == "add") {
      S |= (1 << (num-1)); // 비트 켜기
    }
    else if (act == "remove") {
      S &= ~(1 << (num-1)); // 비트 끄기
    }
    else if (act == "check") {
      cout << ((S & (1 << (num-1))) ? 1 : 0) << '\n';
    }
    else if (act == "toggle") {
      S ^= (1 << (num-1)); // XOR로 토글
    }
    else if (act == "all") {
      S = (1 << 20) - 1; // 모든 비트 켜기
    }
    else if (act == "empty") {
      S = 0; // 모든 비트 끄기
    }
  }

  return 0;
}