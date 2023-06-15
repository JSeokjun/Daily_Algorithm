#include <iostream>
using namespace std;

int main() {
    int M, N, U, L, R, D, row, col, k;
    cin >> M >> N >> U >> L >> R >> D;
    row = M+U+D;
    col = N+L+R;
    char arr[row][col];
    char cw[M][N];
    string str;
 
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(i%2==0 && j%2==0) arr[i][j] = '#';
            else if(i%2!=0 && j%2!=0) arr[i][j] = '#';
            else arr[i][j] = '.';
        }
    }

    for(int i=U; i<row-D; i++) {
        cin >> str;
        k=0;
        for(int j=L; j<col-R; j++) {
            arr[i][j] = str[k];
            k++;
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}