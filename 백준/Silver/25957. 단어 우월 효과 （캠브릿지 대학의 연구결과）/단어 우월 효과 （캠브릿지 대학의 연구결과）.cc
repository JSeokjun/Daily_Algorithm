#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string str, tmp;
    map<string,string> m;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> str;
        tmp = str;
        if(str.length()>3) sort(str.begin()+1, str.end()-1);
        m.insert(make_pair(str,tmp));
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> str;
        if(str.length()>3) sort(str.begin()+1, str.end()-1);
        cout << m[str] << ' ';
    }
}