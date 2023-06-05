#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, num;
    set<int> s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> num;
        s.insert(num);
    }
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++) {
        cout << *it << ' ';
    }   
}