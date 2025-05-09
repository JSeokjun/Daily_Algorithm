#include <iostream>
#include <queue>
using namespace std;

int main() {
    string S, T; cin >> S >> T;
    queue<string> Q;
    
    Q.push(S);

    while (!Q.empty()) {
        string str = Q.front();
        Q.pop();
        
        if (str == T) {
            cout << 1;
            return 0;
        }

        if (str.size()+1 <= T.size()) {
            bool c1 = true, c11 = false, c2 = true, c21 = false;

            for (int i=0; i<T.size()-(str.size()-1); i++) {
                for (int j=0; j<str.size(); j++) {
                    if (str[j] != T[i+j]) {
                        c1 = false;
                        break;
                    }
                }
                if (c1) {
                    c11 = true;
                    break;
                }
                else {
                    c1 = true;
                }
            }

            for (int i=0; i<T.size()-(str.size()-1); i++) {
                for (int j=0; j<str.size(); j++) {
                    if (str[j] != T[T.size()-1-i-j]) {
                        c1 = false;
                        break;
                    }
                }
                if (c1) {
                    c11 = true;
                    break;
                }
                else {
                    c1 = true;
                }
            }

            if (c11 || c21) {
                Q.push(str+"A");

                string reverseStr = "B";
                for (int i=str.size()-1; i>=0; i--) {
                    reverseStr += str[i];
                }
                Q.push(reverseStr);
            }
        }
    }

    cout << 0;

    return 0;
}