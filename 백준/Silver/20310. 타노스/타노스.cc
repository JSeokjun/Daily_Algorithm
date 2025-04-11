// 큐와 벡터를 활용한 버전

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    string S; cin >> S;
    queue<int> Q;
    vector<int> V, answer;
    int num_zero = 0, num_one = 0;

    for (int i=0; i<S.size(); i++) {
        if (S[i] == '0') {
            Q.push(0);
            num_zero++;
        }
        else {
            Q.push(1);
            num_one++;
        }
    }

    num_zero /= 2;
    num_one /= 2;

    while(!Q.empty()) {
        if (num_one != 0 && Q.front() != 0) {
            Q.pop();
            num_one--;
        }
        else {
            V.push_back(Q.front());
            Q.pop();
        }
    }

    while (!V.empty()) {
        if (num_zero != 0 && V.back() == 0) {
            V.pop_back();
            num_zero--;
        }
        else {
            answer.push_back(V.back());
            V.pop_back();
        }
    }

    for (int i=answer.size()-1; i>=0; i--) {
        cout << answer[i];
    }

    return 0;
}
