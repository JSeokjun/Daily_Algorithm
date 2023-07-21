#include <iostream>
#include <set>
using namespace std;

int main() {
	int N;
    string a, b;
    set<string> s;
    cin >> N;
    s.insert("ChongChong");

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        if(s.find(a)!=s.end()) s.insert(b);
        else if(s.find(b)!=s.end()) s.insert(a);
    }

    cout << s.size();
}