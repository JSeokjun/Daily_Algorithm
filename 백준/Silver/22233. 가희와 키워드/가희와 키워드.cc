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

        for (int i=0; i<keyword_list.size(); i++) {
            if (keyword_list[i] == ',') {
                note.erase(keyword);
                keyword = "";
                continue;
            }
            
            keyword += keyword_list[i];

            if (i == keyword_list.size()-1) {
                note.erase(keyword);
            }
        }

        cout << note.size() << '\n';
    }

    return 0;
}