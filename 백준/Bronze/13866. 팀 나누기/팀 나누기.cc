#include <iostream>
using namespace std;
 
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A+D >= B+C) cout << min((C+D)-(A+B), (A+D)-(B+C));
    else cout << min((C+D)-(A+B), (B+C)-(A+D));
    return 0;
}