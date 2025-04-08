// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int N; cin >> N;
//     vector<int> firstVoca(26, 0);
//     vector<int> voca(26, 0);
//     int answer = 0;
//     string str; cin >> str;

//     for (int j=0; j<str.size(); j++) {
//         firstVoca[str[j] - 65]++ ;
//     }

//     for (int i=0; i<N-1; i++) {
//         cin >> str;
//         bool plus = false, minus = false, similar = true;
//         for (int j=0; j<26; j++) {
//             voca[j] = 0;
//         }

//         for (int j=0; j<str.size(); j++) {
//             voca[str[j] - 65]++;
//         }

//         for (int j=0; j<26; j++) {
//             if (firstVoca[j] == voca[j]) {
//                 continue;
//             }
//             else if (firstVoca[j] > voca[j]) {
//                 if (firstVoca[j] - voca[j] > 1) {
//                     similar = false;
//                     break;
//                 }
                
//                 if (!plus) plus = true;
//                 else {
//                     similar = false;
//                     break;
//                 } 
//             }
//             else {
//                 if (voca[j] - firstVoca[j] > 1) {
//                     similar = false;
//                     break;
//                 }

//                 if (!minus) minus = true;
//                 else {
//                     similar = false;
//                     break;
//                 }
//             }
//         }

//         if (similar) answer++;
//     }

//     cout << answer;

//     return 0;
// }

// 문제점 및 개선사항
// 코드 전체적으로는 적절하게 구현되었지만, 몇 가지 개선할 수 있는 부분이 있습니다:

// 가독성 개선:
// 매직 넘버인 65 대신 'A'를 사용하면 더 명확해집니다.
// 변수 이름을 더 명확하게 지정할 수 있습니다 (firstVoca → firstWordCount 등).

// 알고리즘 최적화:
// 현재 구현은 각 단어마다 알파벳 카운트를 확인하고 비교하는 방식이므로 문제 조건에 맞습니다.
// 하지만 가독성을 위해 비슷한 단어 판단 로직을 별도 함수로 분리할 수 있습니다.

// 코드 구조:
// plus, minus 플래그는 좋은 아이디어지만, 변수명이 의미하는 바를 명확히 하면 더 좋을 것 같습니다 (letterAdded, letterRemoved 등).

// 예외 처리:
// 현재 코드는 모든 입력이 올바르다고 가정하고 있습니다. 실제 사용 환경에 따라 입력 유효성 검사가 필요할 수 있습니다.

// 결론
// 전반적으로 코드는 문제 요구사항을 잘 충족하고 있습니다. 시간 복잡도는 O(N * 26)으로 효율적입니다 (N은 단어 수, 26은 알파벳 수). 위에서 언급한 부분들을 개선하면 코드의 가독성과 유지보수성이 더 좋아질 것입니다.
// 문제를 해결하는 접근 방식도 적절합니다. 각 단어의 알파벳 출현 빈도를 세어 비교하는 방식으로 비슷한 단어를 찾아내고 있습니다.

// 개선된 코드
#include <iostream>
#include <vector>

using namespace std;

// 두 단어가 비슷한지 확인하는 함수
bool isSimilarWord(const vector<int>& firstWordCount, const string& word) {
    vector<int> currentWordCount(26, 0);
    
    // 현재 단어의 알파벳 빈도수 계산
    for (char c : word) {
        currentWordCount[c - 'A']++;
    }
    
    bool letterAdded = false;    // 문자가 추가되었는지
    bool letterRemoved = false;  // 문자가 제거되었는지
    
    // 두 단어 비교
    for (int i = 0; i < 26; i++) {
        if (firstWordCount[i] == currentWordCount[i]) {
            continue;
        }
        else if (firstWordCount[i] > currentWordCount[i]) {
            // 첫 번째 단어에서 문자가 제거된 경우
            if (firstWordCount[i] - currentWordCount[i] > 1) {
                return false;  // 2개 이상 차이나면 비슷한 단어가 아님
            }
            
            if (!letterRemoved) {
                letterRemoved = true;
            } else {
                return false;  // 이미 문자가 제거된 적이 있으면 비슷한 단어가 아님
            }
        }
        else {
            // 첫 번째 단어에 문자가 추가된 경우
            if (currentWordCount[i] - firstWordCount[i] > 1) {
                return false;  // 2개 이상 차이나면 비슷한 단어가 아님
            }
            
            if (!letterAdded) {
                letterAdded = true;
            } else {
                return false;  // 이미 문자가 추가된 적이 있으면 비슷한 단어가 아님
            }
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> firstWordCount(26, 0);
    int similarWordCount = 0;
    string firstWord, currentWord;
    
    // 첫 번째 단어 입력 및 알파벳 빈도수 계산
    cin >> firstWord;
    for (char c : firstWord) {
        firstWordCount[c - 'A']++;
    }
    
    // 나머지 단어들 처리
    for (int i = 0; i < N - 1; i++) {
        cin >> currentWord;
        
        if (isSimilarWord(firstWordCount, currentWord)) {
            similarWordCount++;
        }
    }
    
    cout << similarWordCount;
    
    return 0;
}

// 개선된 부분 설명:
// 가독성 향상:
// 매직 넘버 65 대신 'A'를 사용하여 가독성 향상
// 변수명을 더 명확하게 변경 (firstVoca → firstWordCount, plus → letterAdded 등)
// for-each 루프 사용으로 코드를 간결하게 작성

// 코드 구조화:
// 비슷한 단어 판단 로직을 별도 함수 isSimilarWord로 분리
// 함수 분리로 메인 로직 이해가 쉬워짐

// 변수명 개선:
// plus, minus → letterAdded, letterRemoved로 변경하여 의미 명확화
// answer → similarWordCount로 변경하여 변수 목적 명확화
// str → firstWord, currentWord로 변경하여 컨텍스트 추가

// 불필요한 초기화 제거:
// 기존에 매번 voca 배열을 수동으로 초기화하던 부분을 함수 내에서 새 배열 생성으로 대체
// 이 코드는 원래의 알고리즘 흐름과 시간 복잡도를 유지하면서, 가독성과 유지보수성을 크게 향상시켰습니다.
