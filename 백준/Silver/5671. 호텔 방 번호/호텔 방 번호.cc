#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    
    while(cin >> N >> M) {
        int cnt = 0;

        if(M<=10) cout << M-N+1 << '\n';
        else {
            for(int i=N; i<=M; i++) {
                string str = to_string(i);

                if(str.length()==2 && 
                (str[0]==str[1])) cnt++;

                else if(str.length()==3 && 
                (str[0]==str[1] || str[0]==str[2] || 
                str[1]==str[2])) cnt++;

                else if(str.length()==4 && 
                (str[0]==str[1] || str[0]==str[2] || str[0]==str[3] ||
                str[1]==str[2] || str[1]==str[3] ||
                str[2]==str[3])) cnt++; 
            }
            cout << M-N+1-cnt << '\n';
        }
    }

    return 0;
}   