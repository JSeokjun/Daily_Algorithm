#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    string str1, str2;
    cin >> N >> M;
    map<string, string> m;

    for(int i=0; i<N; i++) {
        cin >> str1 >> str2;
        m[str1] = str2;
    }
    for(int i=0; i<M; i++) {
        cin >> str1;
        cout << m.find(str1)->second << '\n';
    }
}