// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <algorithm>

// using namespace std;

// int main() {
//     int T; cin >> T;

//     while(T--) {
//         int n, k, t, m; cin >> n >> k >> t >> m;
//         vector<tuple<int,int,int,int>> teamLog(n);
//         int scoreBoard[n][k];

//         for (int i=0; i<n; i++) {
//             teamLog[i] = {0, 0, 0, 0};
//             for (int j=0; j<k; j++) {
//                 scoreBoard[i][j] = 0;
//             }
//         }

//         for (int time=0; time<m; time++) {
//             int i, j, s; cin >> i >> j >> s;
            
//             if (scoreBoard[i-1][j-1] < s) {
//                 teamLog[i-1] = {i, get<1>(teamLog[i-1])-scoreBoard[i-1][j-1]+s, get<2>(teamLog[i-1])+1, time};
//                 scoreBoard[i-1][j-1] = s;
//             }
//             else {
//                 teamLog[i-1] = {i, get<1>(teamLog[i-1]), get<2>(teamLog[i-1])+1, time};
//             }
//         }

//         sort(teamLog.begin(), teamLog.end(), [](auto &a, auto &b){
//             if (get<1>(a) != get<1>(b)) {
//                 return get<1>(a) > get<1>(b);
//             }
//             if (get<2>(a) != get<2>(b)) {
//                 return get<2>(a) < get<2>(b);
//             }
//             return get<3>(a) < get<3>(b);
//         });

//         int rank = 1;

//         for (int i=0; i<n; i++) {
//             if (get<0>(teamLog[i]) == t) {
//                 cout << rank << '\n';
//                 break;
//             }

//             if (get<1>(teamLog[i]) != get<1>(teamLog[i+1]) || 
//                 get<2>(teamLog[i]) != get<2>(teamLog[i+1]) || 
//                 get<3>(teamLog[i]) != get<3>(teamLog[i+1])) {
//                     rank = i+2;
//                 }
//         }    
//     }
    
//     return 0;
// }

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;

    while(T--) {
        int n, k, t, m; cin >> n >> k >> t >> m;
        vector<tuple<int,int,int,int>> teamLog(n);  // (팀ID, 총점, 제출 횟수, 마지막 제출 시간)
        vector<vector<int>> scoreBoard(n, vector<int>(k, 0));

        // 초기화
        for (int i=0; i<n; i++) {
            teamLog[i] = {i+1, 0, 0, 0};  // 팀ID는 1부터 시작하므로 i+1로 설정
        }

        // 로그 처리
        for (int time=0; time<m; time++) {
            int i, j, s; cin >> i >> j >> s;
            i--; j--;  // 0-index로 변환
            
            if (scoreBoard[i][j] < s) {
                // 점수 업데이트
                get<1>(teamLog[i]) += (s - scoreBoard[i][j]);
                scoreBoard[i][j] = s;
            }
            
            // 제출 횟수와 마지막 제출 시간 업데이트
            get<2>(teamLog[i])++;
            get<3>(teamLog[i]) = time;
        }

        // 정렬
        sort(teamLog.begin(), teamLog.end(), [](auto &a, auto &b){
            // 1. 총점이 높은 순
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b);
            }
            // 2. 제출 횟수가 적은 순
            if (get<2>(a) != get<2>(b)) {
                return get<2>(a) < get<2>(b);
            }
            // 3. 마지막 제출 시간이 빠른 순
            return get<3>(a) < get<3>(b);
        });

        // 순위 찾기
        int rank = 1;
        for (int i=0; i<n; i++) {
            if (get<0>(teamLog[i]) == t) {
                cout << rank << '\n';
                break;
            }
            
            // 다음 팀과 비교하여 순위 갱신
            if (i+1 < n && (get<1>(teamLog[i]) != get<1>(teamLog[i+1]) || 
                get<2>(teamLog[i]) != get<2>(teamLog[i+1]) || 
                get<3>(teamLog[i]) != get<3>(teamLog[i+1]))) {
                rank = i+2;
            }
        }
    }
    
    return 0;
}

// 주요 개선 사항

// 가독성과 효율성:
// vector<vector<int>> 사용하여 VLA 대신 표준 컨테이너 사용
// 팀 로그 업데이트 방식 개선
// 인덱스 변환 (1-indexed에서 0-indexed로)를 명시적으로 처리

// 메모리 관리:
// 가변 길이 배열(VLA) 대신 표준 벡터 사용으로 안정성 향상
// 원래 코드도 기능적으로는 대부분 정확하지만, 위의 개선사항을 적용하면 코드가 더 안정적이고 가독성이 높아질 것입니다.