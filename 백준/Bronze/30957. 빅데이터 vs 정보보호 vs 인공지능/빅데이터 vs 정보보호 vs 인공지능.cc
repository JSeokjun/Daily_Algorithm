#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    string str; cin >> str;
    int B=0, S=0, A=0;

    for(int i=0; i<N; i++) {
        if(str[i]=='B') B++;
        else if(str[i]=='S') S++;
        else if(str[i]=='A') A++;
    }

    if(B==S && B==A) cout << "SCU";
    else if(B>=S && B>=A) {
        if(B == S) cout << "BS";
        else if(B == A) cout << "BA";
        else cout << "B";
    }
    else if(S>=B && S>=A) {
        if(S == B) cout << "BS";
        else if(S == A) cout << "SA";
        else cout << "S";
    }
    else if(A>=B && A>=S) {
        if(A == B) cout << "BA";
        else if(A == S) cout << "SA";
        else cout << "A";
    }

    return 0; 
}   