#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N; cin >> N;
  int heart_x = 0, heart_y = 0, waist_len = 0, left_arm_len = 0, right_arm_len = 0, left_leg_len = 0, right_leg_len = 0;
  bool check_head = false;


  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      char body; cin >> body;

      if (body == '*') {
        
        if (!check_head) {
          heart_x = i+1;
          heart_y = j;
          check_head = true;
        }

        if (i == heart_x && j < heart_y) left_arm_len++;
        else if (i == heart_x && j > heart_y) right_arm_len++;
        else if (i > heart_x && j == heart_y) waist_len++;
        else if (i > heart_x && j == heart_y-1) left_leg_len++;
        else if (i > heart_x && j == heart_y+1) right_leg_len++;
      }
    }
  }

  cout << heart_x << ' ' << heart_y << '\n' << left_arm_len << ' ' << right_arm_len << ' ' << waist_len << ' ' << left_leg_len << ' ' << right_leg_len;

  return 0;
}