#include <iostream>
#include <vector>
using namespace std;

vector<bool> alphabet(26, false);

bool checkAlphabet(char ch) {
    if (ch == 'A' || ch == 'a') {
        bool result = alphabet[0] ? true : false;
        alphabet[0] = true;
        return result;
    }
    else if (ch == 'B' || ch == 'b') {
        bool result = alphabet[1] ? true : false;
        alphabet[1] = true;
        return result;
    }
    else if (ch == 'C' || ch == 'c') {
        bool result = alphabet[2] ? true : false;
        alphabet[2] = true;
        return result;
    }
    else if (ch == 'D' || ch == 'd') {
        bool result = alphabet[3] ? true : false;
        alphabet[3] = true;
        return result;
    }
    else if (ch == 'E' || ch == 'e') {
        bool result = alphabet[4] ? true : false;
        alphabet[4] = true;
        return result;
    }
    else if (ch == 'F' || ch == 'f') {
        bool result = alphabet[5] ? true : false;
        alphabet[5] = true;
        return result;
    }
    else if (ch == 'G' || ch == 'g') {
        bool result = alphabet[6] ? true : false;
        alphabet[6] = true;
        return result;
    }
    else if (ch == 'H' || ch == 'h') {
        bool result = alphabet[7] ? true : false;
        alphabet[7] = true;
        return result;
    }
    else if (ch == 'I' || ch == 'i') {
        bool result = alphabet[8] ? true : false;
        alphabet[8] = true;
        return result;
    }
    else if (ch == 'J' || ch == 'j') {
        bool result = alphabet[9] ? true : false;
        alphabet[9] = true;
        return result;
    }
    else if (ch == 'K' || ch == 'k') {
        bool result = alphabet[10] ? true : false;
        alphabet[10] = true;
        return result;
    }
    else if (ch == 'L' || ch == 'l') {
        bool result = alphabet[11] ? true : false;
        alphabet[11] = true;
        return result;
    }
    else if (ch == 'M' || ch == 'm') {
        bool result = alphabet[12] ? true : false;
        alphabet[12] = true;
        return result;
    }
    else if (ch == 'N' || ch == 'n') {
        bool result = alphabet[13] ? true : false;
        alphabet[13] = true;
        return result;
    }
    else if (ch == 'O' || ch == 'o') {
        bool result = alphabet[14] ? true : false;
        alphabet[14] = true;
        return result;
    }
    else if (ch == 'P' || ch == 'p') {
        bool result = alphabet[15] ? true : false;
        alphabet[15] = true;
        return result;
    }
    else if (ch == 'Q' || ch == 'q') {
        bool result = alphabet[16] ? true : false;
        alphabet[16] = true;
        return result;
    }
    else if (ch == 'R' || ch == 'r') {
        bool result = alphabet[17] ? true : false;
        alphabet[17] = true;
        return result;
    }
    else if (ch == 'S' || ch == 's') {
        bool result = alphabet[18] ? true : false;
        alphabet[18] = true;
        return result;
    }
    else if (ch == 'T' || ch == 't') {
        bool result = alphabet[19] ? true : false;
        alphabet[19] = true;
        return result;
    }
    else if (ch == 'U' || ch == 'u') {
        bool result = alphabet[20] ? true : false;
        alphabet[20] = true;
        return result;
    }
    else if (ch == 'V' || ch == 'v') {
        bool result = alphabet[21] ? true : false;
        alphabet[21] = true;
        return result;
    }
    else if (ch == 'W' || ch == 'w') {
        bool result = alphabet[22] ? true : false;
        alphabet[22] = true;
        return result;
    }
    else if (ch == 'X' || ch == 'x') {
        bool result = alphabet[23] ? true : false;
        alphabet[23] = true;
        return result;
    }
    else if (ch == 'Y' || ch == 'y') {
        bool result = alphabet[24] ? true : false;
        alphabet[24] = true;
        return result;
    }
    else if (ch == 'Z' || ch == 'z') {
        bool result = alphabet[25] ? true : false;
        alphabet[25] = true;
        return result;
    }
    else {
        return -1;
    }
}

int main() {
    int N; cin >> N;
    getchar();
    vector<vector<string>> V(N);
    vector<pair<int,int>> L(N);

    for (int i=0; i<N; i++) {
        string str = "";
        getline(cin, str);
        int startIndex = 0;
        string sliceStr = "";
        for (int j=0; j<str.size(); j++) {
            if (str[j] == ' ') {
                sliceStr = "";
                for (int k=startIndex; k<j; k++) {
                    sliceStr += str[k];
                }
                V[i].push_back(sliceStr);
                startIndex = j+1;
            }
        }
        sliceStr = "";
        for (int k=startIndex; k<str.size(); k++) {
            sliceStr += str[k];
        }
        V[i].push_back(sliceStr);
    }

    for (int i=0; i<N; i++) {
        bool isSet = false;
        for (int j=0; j<V[i].size(); j++) {
            if (!checkAlphabet(V[i][j][0])) {
                L[i] = {j,0};
                isSet = true;
                break;
            }
        }
        if (!isSet) {
            for (int j=0; j<V[i].size(); j++) {
                for (int k=1; k<V[i][j].size(); k++) {
                    if (!checkAlphabet(V[i][j][k])) {
                        L[i] = {j,k};
                        isSet = true;
                        break;
                    }
                }
                if (isSet) break;
            }
            if (!isSet) {
                L[i] = {-1, -1};
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<V[i].size(); j++) {
            for (int k=0; k<V[i][j].size(); k++) {
                if (j == L[i].first && k == L[i].second) cout << '[' << V[i][j][k] << ']';
                else cout << V[i][j][k];
            }
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}