#include <iostream>
using namespace std;

int main() {
    int jun, ik;
    cin >> jun >> ik;

    if(jun == 0) {
        if(ik == 0) cout << '=';
        else if(ik == 2) cout << '>';
        else if(ik == 5) cout << '<';
        else cout << '>';
    }
    else if(jun == 2) {
        if(ik == 0) cout << '<';
        else if(ik == 2) cout << '=';
        else if(ik == 5) cout << '>';
        else cout << '>';
    }
    else if(jun == 5) {
        if(ik == 0) cout << '>';
        else if(ik == 2) cout << '<';
        else if(ik == 5) cout << '=';
        else cout << '>';
    }
    else {
        if(ik == 0) cout << '<';
        else if(ik == 2) cout << '<';
        else if(ik == 5) cout << '<';
        else cout << '=';
    }
    
    return 0;
}