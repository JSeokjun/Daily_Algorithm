#include <iostream>
using namespace std;

char arr[3*3*3*3*3*3*3*3*3*3*3*3+1];

void Canto(int size, int i) {
    if(size==1) {
        arr[i] = '-';
    }
    else {
        Canto(size/3, i);
        Canto(size/3, i+size/3*2);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    
    while(cin >> N) {
        int size = 1;
        for(int i=0; i<N; i++) size*=3;

        Canto(size, 0);

        for(int i=0; i<size; i++) {
            if(arr[i]=='-') cout << '-'; 
            else cout << ' ';
        }
        cout << '\n';
    } 

    return 0;
}   