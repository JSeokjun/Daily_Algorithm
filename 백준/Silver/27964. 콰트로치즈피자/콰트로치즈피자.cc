#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N;
    string str;
    set<string> s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> str;
        if(str.length()<6) continue;
        if(str.substr(str.length()-6)=="Cheese") {
            s.insert(str);
        }
    }
    if(s.size()>=4) cout << "yummy";
    else cout << "sad";
}