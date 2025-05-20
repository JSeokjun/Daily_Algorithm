#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;

    while(T--) {
        string str; cin >> str;
        int K; cin >> K;
        int len_min_str = 10001, len_max_str = 0;
        vector<vector<int>> position(26);

        for (int i=0; i<str.size(); i++) {
            position[str[i]-'a'].push_back(i);
        }

        for (int i=0; i<26; i++) {
            if (position[i].size() < K) continue;

            for (int j=0; j+K-1<position[i].size(); j++) {
                int begin = position[i][j];
                int end = position[i][j+K-1];
                int len = end - begin + 1;

                if (str[begin] == str[end] && len_max_str < len) {
                    len_max_str = len;
                }
                if (len_min_str > len) {
                    len_min_str = len;
                }
            }
        }

        if (len_min_str == 10001 || len_max_str == 0) {
            cout << -1 << '\n';
        }
        else {
            cout << len_min_str << ' ' << len_max_str << '\n';
        }
    }
    
    return 0;
}