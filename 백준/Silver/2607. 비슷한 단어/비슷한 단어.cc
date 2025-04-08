#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> firstVoca(26, 0);
    vector<int> voca(26, 0);
    int answer = 0;
    string str; cin >> str;

    for (int j=0; j<str.size(); j++) {
        firstVoca[str[j] - 65]++ ;
    }

    for (int i=0; i<N-1; i++) {
        cin >> str;
        bool plus = false, minus = false, similar = true;
        for (int j=0; j<26; j++) {
            voca[j] = 0;
        }

        for (int j=0; j<str.size(); j++) {
            voca[str[j] - 65]++;
        }

        for (int j=0; j<26; j++) {
            if (firstVoca[j] == voca[j]) {
                continue;
            }
            else if (firstVoca[j] > voca[j]) {
                if (firstVoca[j] - voca[j] > 1) {
                    similar = false;
                    break;
                }
                
                if (!plus) plus = true;
                else {
                    similar = false;
                    break;
                } 
            }
            else {
                if (voca[j] - firstVoca[j] > 1) {
                    similar = false;
                    break;
                }

                if (!minus) minus = true;
                else {
                    similar = false;
                    break;
                }
            }
        }

        if (similar) answer++;
    }

    cout << answer;

    return 0;
}