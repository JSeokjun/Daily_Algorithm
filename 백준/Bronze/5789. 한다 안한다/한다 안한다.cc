#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> str;
        if(str[str.length()/2-1]==str[str.length()/2]) cout << "Do-it" << '\n';
        else cout << "Do-it-Not" << '\n';
    }
}