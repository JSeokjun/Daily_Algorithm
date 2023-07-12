#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, t, a, max_size=0, min_num=100000;
    cin >> n;
    queue<int> q;
    for(int i=0; i<n; i++) {
        cin >> t;
        if(t==1) {
            cin >> a;
            q.push(a);
        }
        else q.pop();

        if(q.size()>max_size) {
            min_num=q.back();
            max_size=q.size();
        }
        else if(q.size()==max_size) {
            if(min_num>q.back()) min_num=q.back(); 
        } 
    }
    cout << max_size << ' ' << min_num;
}