#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M;
    string str;
    cin >> N >> M;
    set<string> s1;
    set<string> s2;

    for(int i=0; i<N; i++) {
        cin >> str;
        s1.insert(str);
    }
    for(int i=0; i<M; i++) {
        cin >> str;
        auto it = s1.find(str);
        if(it!=s1.end()) s2.insert(str);  
    }
    cout << s2.size() << '\n';
    for(set<string>::iterator iter=s2.begin(); iter!=s2.end(); iter++) {
        cout << *iter << '\n';
    }
}