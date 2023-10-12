#include <iostream>
using namespace std;

int N, w=0, b=0, arr[128][128];

void paper(int row_s, int row_e, int col_s, int col_e) {
    int tmp; bool check=1;
    tmp = arr[row_s][col_s];
    for(int i=row_s; i<row_e; i++) {
        for(int j=col_s; j<col_e; j++) {
            if(arr[i][j]!=tmp) {
                check=0;
                break;
            } 
        }
        if(!check) break;
    }
    if((row_e-row_s)==1 && (col_e-col_s)==1) {
        if(tmp==0) w++;
        else b++; 
    }
    else if(check) {
        if(tmp==0) w++;
        else b++;
    }
    else {
        paper(row_s, (row_s+row_e)/2, col_s, (col_s+col_e)/2);
        paper(row_s, (row_s+row_e)/2, (col_s+col_e)/2, col_e);
        paper((row_s+row_e)/2, row_e, col_s, (col_s+col_e)/2);
        paper((row_s+row_e)/2, row_e, (col_s+col_e)/2, col_e);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j]; 
        }
    }

    paper(0, N, 0, N);
    cout << w << '\n' << b;
}   