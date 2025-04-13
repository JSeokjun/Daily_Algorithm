#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    set<string> note;

    while (N--) {
        string keyword; cin >> keyword;
        note.insert(keyword);
    }

    while (M--) {
        string keyword_list; cin >> keyword_list;
        string keyword = "";

        for (int i=0; i<=keyword_list.size(); i++) {
            if (i == keyword_list.size() || keyword_list[i] == ',') {
                // 메모장에 있는 키워드만 삭제
                if (!keyword.empty() && note.find(keyword) != note.end()) {
                    note.erase(keyword);
                }
                keyword = "";
            } else {
                keyword += keyword_list[i];
            }
        }

        cout << note.size() << '\n';
    }

    return 0;
}

// 개선 내용:
// 이제 메모장에 있는 키워드만 삭제합니다 (note.find(keyword) != note.end() 조건 추가)
// 문자열 끝과 쉼표를 같은 로직으로 처리하여 코드 중복을 제거했습니다.
// 빈 키워드(empty())를 체크하여 오류를 방지했습니다.