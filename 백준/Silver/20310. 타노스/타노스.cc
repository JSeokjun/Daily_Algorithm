#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    string S; cin >> S;
    vector<int> V;
    int num_zero = 0, num_one = 0;

    for (int i=0; i<S.size(); i++) {
        if (S[i] == '0') {
            V.push_back(0);
            num_zero++;
        }
        else {
            V.push_back(1);
            num_one++;
        }
    }

    num_zero /= 2;
    num_one /= 2;

    for (int i=V.size()-1; i>=0; i--) {
        if (V[i] == 0) {
            V.erase(V.begin()+i);
            num_zero--;
        }
        if (num_zero == 0) break;
    }

    for (int i=0; i<V.size(); i++) {
        if (V[i] == 1) {
            V.erase(V.begin()+i);
            num_one--;
        }
        if (num_one == 0) break;
    }

    for (int i=0; i<V.size(); i++) {
        cout << V[i];
    }

    return 0;
}