#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int N, M, num, cnt;
    map<int,int> m;
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> num;
        if(m.find(num)!=m.end()) {
            cnt = m[num];
            m.erase(num);
            m.insert(make_pair(num,cnt+1));
        }
        else {
            m.insert(make_pair(num,1));
        }
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> num;
        if(m.find(num)==m.end()) cout << 0 << ' ';
        else cout << m[num] << ' ';
    }
}