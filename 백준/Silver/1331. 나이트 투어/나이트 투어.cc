#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    set<string> S;
    string str, tmp, start;

    cin >> tmp;
    start = tmp;
    S.insert(tmp);

    for(int i=0; i<35; i++) {
        cin >> str;
        if(!((char)(tmp[0]+1)==str[0] && tmp[1]+2==str[1]+0 ||
        (char)(tmp[0]-1)==str[0] && tmp[1]+2==str[1]+0 ||
        (char)(tmp[0]+1)==str[0] && tmp[1]-2==str[1]+0 ||
        (char)(tmp[0]-1)==str[0] && tmp[1]-2==str[1]+0 ||
        (char)(tmp[0]+2)==str[0] && tmp[1]+1==str[1]+0 ||
        (char)(tmp[0]-2)==str[0] && tmp[1]+1==str[1]+0 ||
        (char)(tmp[0]+2)==str[0] && tmp[1]-1==str[1]+0 ||
        (char)(tmp[0]-2)==str[0] && tmp[1]-1==str[1]+0)) {
            cout << "Invalid";
            return 0;
        } 
        S.insert(str);
        tmp = str;
    }

    if(!((char)(tmp[0]+1)==start[0] && tmp[1]+2==start[1]+0 ||
        (char)(tmp[0]-1)==start[0] && tmp[1]+2==start[1]+0 ||
        (char)(tmp[0]+1)==start[0] && tmp[1]-2==start[1]+0 ||
        (char)(tmp[0]-1)==start[0] && tmp[1]-2==start[1]+0 ||
        (char)(tmp[0]+2)==start[0] && tmp[1]+1==start[1]+0 ||
        (char)(tmp[0]-2)==start[0] && tmp[1]+1==start[1]+0 ||
        (char)(tmp[0]+2)==start[0] && tmp[1]-1==start[1]+0 ||
        (char)(tmp[0]-2)==start[0] && tmp[1]-1==start[1]+0)) {
            cout << "Invalid";
            return 0;
        }

    if(S.size()==36) cout << "Valid";
    else cout << "Invalid";

    return 0;
}   