#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string N; cin >> N;
    int cnt = 0;

    while(1) {
        while(N.find('1') != string::npos) {
            if(N == "1") {
                cout << cnt+1;
                return 0;
            }  
            N.erase(N.find('1'),1);
            cnt++;
        }
        
        int tmp = stoi(N);
        
        while(N.find('1') == string::npos) {
            if(tmp == 0) {
                cout << cnt;
                return 0;
            }
            tmp -= 1;
            cnt++;
            N = to_string(tmp);
        }
    }

    return 0;
}   