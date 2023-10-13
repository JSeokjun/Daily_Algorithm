#include <iostream>
using namespace std;

char video[64][64];
string zip = "";

void QuadTree(int row_s, int row_e, int col_s, int col_e) {
    char tmp = video[row_s][col_s];
    bool check = 0;
    
    for(int i=row_s; i<row_e; i++) {
        for(int j=col_s; j<col_e; j++) {
            if(video[i][j]!=tmp) {
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    
    if(!check) zip += tmp;
    else {
        zip += '(';
        QuadTree(row_s, (row_s+row_e)/2, col_s, (col_s+col_e)/2);
        QuadTree(row_s, (row_s+row_e)/2, (col_s+col_e)/2, col_e);
        QuadTree((row_s+row_e)/2, row_e, col_s, (col_s+col_e)/2);
        QuadTree((row_s+row_e)/2, row_e, (col_s+col_e)/2, col_e);
        zip += ')';
    }  
}

int main() {
    int N; cin >> N;

    for(int i=0; i<N; i++) {
        string tmp; cin >> tmp;
        for(int j=0; j<N; j++) {
            video[i][j] = tmp[j];
        }
    }

    QuadTree(0, N, 0, N);
    cout << zip;

    return 0; 
}   