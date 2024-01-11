#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    stack<int> s1, s2;
    int tmp; cin >> tmp;
    int* cnt = new int[1000000];

    if(tmp != 1) {
        cout << -1;
        return 0;
    }
    else s1.push(tmp);
    
    for(int i=0; i<N-1; i++) {
        int L; cin >> L;
        if(s1.top()+1 < L) {
            cout << -1;
            return 0;
        }
        s1.push(L);
        cnt[L] = 0;
    }

    while(!s1.empty()) {
		s2.push(cnt[s1.top()]);
		cnt[s1.top()] = 0;
		cnt[s1.top() - 1]++;
		s1.pop();
	}

	while(!s2.empty()) {
		cout << s2.top() << '\n';
		s2.pop();
	}

    delete[] cnt;

    return 0;
}