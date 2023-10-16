#include <iostream>
using namespace std;

int cnt;

int recursion(string &s, int l, int r) {
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string &s) {
    return recursion(s, 0, s.length()-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    int T; cin >> T;
    
    for(int i=0; i<T; i++) {
        cnt = 0;
        cin >> s;
        cout << isPalindrome(s) << ' ';
        cout << cnt << '\n';
    }
    
    return 0; 
}   