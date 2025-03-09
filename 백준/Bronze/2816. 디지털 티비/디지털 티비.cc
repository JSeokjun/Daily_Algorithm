#include <iostream>

using namespace std;

int main() {
  int N = 0, loc_1 = 0, loc_2 = 0;
  string channel = "";
  cin >> N;

  for(int i=0; i<N; i++) {
    cin >> channel;

    if (channel == "KBS1") {
      loc_1 = i;
    } 
    else if (channel == "KBS2") {
      loc_2 = i;
    }
  }

  if (loc_1 > 0) {
    for(int i=0; i<loc_1; i++) {
      cout << "1";
    }
    for(int i=0; i<loc_1; i++) {
      cout << "4";
    }
  }

  if (loc_2 > 1) {
    if (loc_1 > loc_2) {
      for(int i=0; i<loc_2+1; i++) {
        cout << "1";
      }
      for(int i=0; i<loc_2; i++) {
        cout << "4";
      }
    }
    else {
      for(int i=0; i<loc_2; i++) {
        cout << "1";
      }
      for(int i=0; i<loc_2-1; i++) {
        cout << "4";
      }
    }
  }

  return 0;
}