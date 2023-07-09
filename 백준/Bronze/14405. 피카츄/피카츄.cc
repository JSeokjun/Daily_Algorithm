#include <iostream>
using namespace std;

int main() {
    int i=0;
    string S;
    cin >> S;
    while(S.length()!=i) {
        if(S[i]=='p') {
            i++;
            if(S[i]=='i') i++;
            else {
                cout << "NO";
                return 0;
            }
        }
        else if(S[i]=='k') {
            i++;
            if(S[i]=='a') i++;
            else {
                cout << "NO";
                return 0;
            }
        }
        else if(S[i]=='c') {
            i++;
            if(S[i]=='h') {
                i++;
                if(S[i]=='u') i++;
                else {
                    cout << "NO";
                    return 0;
                }
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}