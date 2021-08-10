#include <iostream>
#include<bits/stdc++.h>
// moores voting machine algorithm
using namespace std;

int majorityElement(vector<int> &nums) {
  int count = 0;
  int candidate= 0;
  for ( auto num: nums) {
    if (count == 0) {
      candidate = num;
    }
    if ( num == candidate ) {
        count +=1;
    } else {
      count -= 1;
    }
  }
  return candidate;
}
int main() {
  vector<int> nums = {2,2,1,1,1,2,2};
  cout<< "Majority Element is " ;
  cout << majorityElement(nums) << endl;
  return 0;
}
