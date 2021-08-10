#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/4sum/

vector<vector<int>> fourSum(vector<int> &nums, int target) {
  vector<vector<int>> res;

  if (nums.empty()) return res;
  int n = nums.size();

  sort(nums.begin(), nums.end());
  // sort the vector
  for( int i =0; i< n;i++) {
    for( int j=i +1; j < n; j++ ) {

      int target_2 = target - nums[i] - nums[j];
      int front = j +1;
      int back = n -1;

      while ( front < back) {
        int two_sum = nums[front] + nums[back];
        if ( target_2 < two_sum) {
          back--;
        } else if (target_2 > two_sum) {
          front++;
        } else {
          vector<int> quadruple(4, 0);
          quadruple[0] = nums[i];
          quadruple[1] = nums[j];
          quadruple[2] = nums[front];
          quadruple[3] = nums[back];
          res.push_back(quadruple);

          //processing the duplicates for 3rd item
          while( front < back && nums[front] == quadruple[2]) ++front;

          // processing the duplicates for 4th item

          while( front < back && nums[back] == quadruple[3]) --back;
        }
      }

      // Processing the duplicates of numer 2nd posittion
      // ... 2 2 2 3
      while(j +1 < n && nums[j + 1] == nums[j]) ++j;
    }

    // processing the duplicates for number first position
    while(i +1 < n && nums[i +1] == nums[i]) ++i;
  }

  return res;
}

void printVectorIterator(vector<vector<int>> &printV) {
  vector<vector<int>>::iterator row;
  vector<int>::iterator col;
  for( row = printV.begin(); row != printV.end() ; row++) {
    for( col = row->begin(); col != row->end(); col++) {
        cout << *(col) << " ";
        //printV[row][col];
    }
    cout <<  endl;
  }
}

void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[i].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}
int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    cout << "Four sum of target value "<< target <<  "is"  << endl;
    printVectorIterator(res);
    return 0;
}
