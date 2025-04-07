#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

// 방향 상수 정의
const int dx[] = {1, 1, 1};    // 아래로 이동
const int dy[] = {-1, 0, 1};   // 왼쪽 대각선, 수직, 오른쪽 대각선

int main() {
    int N, M;
    cin >> N >> M;
    
    // 벡터를 사용하여 행렬 선언
    vector<vector<int>> matrix(N, vector<int>(M));
    
    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // BFS를 위한 큐와 최소 연료값 초기화
    queue<tuple<int,int,int,int>> Q;  // {x, y, 연료, 이전방향}
    int min_fuel = 600;
    
    // 첫 줄에서 시작점 모두 큐에 넣기
    for (int i = 0; i < M; i++) {
        Q.push({0, i, matrix[0][i], -1});  // -1은 초기 방향
    }
    
    // BFS 탐색
    while (!Q.empty()) {
        tuple<int,int,int,int> current = Q.front();
        int x = get<0>(current);
        int y = get<1>(current);
        int fuel = get<2>(current);
        int last_dir = get<3>(current);
        Q.pop();
        
        // 세 방향으로 이동 시도
        for (int dir = 0; dir < 3; dir++) {
            if (dir == last_dir) continue;  // 같은 방향으로 연속 이동 불가
            
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // 경계 검사
            if (ny < 0 || ny >= M) continue;
            
            // 달에 도착한 경우
            if (nx == N-1) {
                min_fuel = min(min_fuel, fuel + matrix[nx][ny]);
                continue;
            }
            
            // 다음 위치로 이동
            Q.push({nx, ny, fuel + matrix[nx][ny], dir});
        }
    }
    
    cout << min_fuel;
    return 0;
}

// 코드를 리뷰해드리겠습니다.
// 전반적으로 BFS를 사용하여 문제를 잘 해결하셨습니다. 몇 가지 개선할 수 있는 부분을 설명드리겠습니다:

// 1. vector를 사용하여 동적 배열 구현 (가변 크기 배열(VLA) 대신 vector를 사용하는 것이 더 안전)
// 2. 방향 배열(dx, dy)을 사용하여 이동 로직 단순화
// 3. 변수명을 더 명확하게 변경 (g → fuel, l → last_dir 등)
// 4. 경계 검사 로직 개선

// 개선사항 요약:
// 메모리 안전성을 위해 vector 사용을 권장합니다.
// 방향 배열을 사용하여 코드를 더 명확하게 만들 수 있습니다.
// 변수명을 더 명확하게 지정하면 코드 이해도가 높아집니다.
// 경계 검사를 더 명확하게 구조화할 수 있습니다.
// 또한 시간 복잡도는 O(NM3)으로 적절합니다. 공간 복잡도는 O(NM)입니다.
// 전반적으로 문제를 잘 해결하셨고, 위의 개선사항들은 코드의 가독성과 유지보수성을 높이기 위한 제안사항입니다.
