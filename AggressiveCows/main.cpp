#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stable_position, int stable_size , int cows, int minDist) {
  int cntCows = 0;
  int lastPlacedCow = 0;
  for (int i =0 ; i< stable_size ; i++) {
      if (stable_position[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = stable_position[i];
      }
  }
  if (cntCows >= cows) return true;
  return false;
}


int findAggresiveCows(int cows, vector<int> &stable_position) {
    sort(stable_position.begin(), stable_position.end());
    int low = 1;
    int stable_size = stable_position.size();
    int high = stable_position[stable_size - 1] - stable_position[0];

    while (low <= high) {
        int mid = (low + high) >> 2;
        if( isPossible(stable_position, stable_size, cows, mid )) {
            low = mid + 1;
        } else {
            high = mid -1;
        }

    }
    cout<< high << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
