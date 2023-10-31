#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=1000; i<=9999; i++) {
        int sum10=0, sum12=0, sum16=0;
        
        sum10 += i%10;
        sum10 += (int)i%100*0.1;
        sum10 += (int)i%1000*0.01;
        sum10 += (int)i*0.001;

        int num = i; 
        while(num!=0) {
            sum12 += (num%12); 
            num /= 12;    
        }

        num = i;
        while(num!=0) {
            sum16 += (num%16); 
            num /= 16;    
        }
        if(sum10==sum12 && sum12==sum16) cout << i << '\n';
    }

    return 0; 
}   