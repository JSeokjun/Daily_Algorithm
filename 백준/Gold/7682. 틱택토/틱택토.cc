#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        string ttt; cin >> ttt;

        if (ttt == "end") return 0;

        int x_cnt = 0, o_cnt = 0;

        for (int i=0; i<9; i++) {
            if (ttt[i] == 'X') x_cnt++;
            else if (ttt[i] == 'O') o_cnt++;
        }

        bool x_win = false, o_win = false;

        if (ttt[0] == 'O' && ttt[0] == ttt[1] && ttt[1] == ttt[2] ||
            ttt[3] == 'O' && ttt[3] == ttt[4] && ttt[4] == ttt[5] ||
            ttt[6] == 'O' && ttt[6] == ttt[7] && ttt[7] == ttt[8] ||
            ttt[0] == 'O' && ttt[0] == ttt[3] && ttt[3] == ttt[6] ||
            ttt[1] == 'O' && ttt[1] == ttt[4] && ttt[4] == ttt[7] ||
            ttt[2] == 'O' && ttt[2] == ttt[5] && ttt[5] == ttt[8] ||
            ttt[0] == 'O' && ttt[0] == ttt[4] && ttt[4] == ttt[8] ||
            ttt[2] == 'O' && ttt[2] == ttt[4] && ttt[4] == ttt[6]
        ) {
            o_win = true;
        }

        if (ttt[0] == 'X' && ttt[0] == ttt[1] && ttt[1] == ttt[2] ||
            ttt[3] == 'X' && ttt[3] == ttt[4] && ttt[4] == ttt[5] ||
            ttt[6] == 'X' && ttt[6] == ttt[7] && ttt[7] == ttt[8] ||
            ttt[0] == 'X' && ttt[0] == ttt[3] && ttt[3] == ttt[6] ||
            ttt[1] == 'X' && ttt[1] == ttt[4] && ttt[4] == ttt[7] ||
            ttt[2] == 'X' && ttt[2] == ttt[5] && ttt[5] == ttt[8] ||
            ttt[0] == 'X' && ttt[0] == ttt[4] && ttt[4] == ttt[8] ||
            ttt[2] == 'X' && ttt[2] == ttt[4] && ttt[4] == ttt[6]
        ) {
            x_win = true;
        }

        if (o_win && x_win) {
            cout << "invalid" << '\n';
            continue;
        }
        else if (o_win && o_cnt == x_cnt) {
            cout << "valid" << '\n';
            continue;
        }
        else if (x_win && o_cnt + 1 == x_cnt) {
            cout << "valid" << '\n';
            continue;
        }
        else if (x_cnt == 5 && o_cnt == 4 && !o_win && !x_win) {
            cout << "valid" << '\n';
            continue;
        } 

        cout << "invalid" << '\n';
    }

    return 0;
}