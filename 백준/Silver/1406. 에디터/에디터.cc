#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    list<char> editor(str.begin(), str.end());
    auto cursor_iter = editor.end();

    int M; cin >> M;

    while(M--) {
        char command; cin >> command;
        
        if (command == 'L') {
            if (cursor_iter != editor.begin()) {
                cursor_iter--;
            }
        }
        else if (command == 'D') {
            if (cursor_iter != editor.end()) {
                cursor_iter++;
            }
        }
        else if (command == 'B') {
            if (cursor_iter != editor.begin()) {
                cursor_iter = editor.erase(prev(cursor_iter));
            }
        }
        else if (command == 'P') {
            char input_char; cin >> input_char;
            editor.insert(cursor_iter, input_char);
        }
    }

    for (auto it = editor.begin(); it != editor.end(); ++it) {
        cout << *it;
    }

    return 0;
}
