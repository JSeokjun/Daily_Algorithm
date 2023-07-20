#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, size, cnt=0;
    string str;
    set<string> s;
    vector<string> v;
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        cin >> str;
        s.insert(str);
    }
    for(int i=0; i<M; i++) {
        size = s.size();
        cin >> str;
        if(find(v.begin(),v.end(),str)!=v.end()) continue;

        s.insert(str);

        if(s.size()>size) {
            v.push_back(str);
        }
        else cnt++;
    }
    
    cout << cnt;
    return 0;
}