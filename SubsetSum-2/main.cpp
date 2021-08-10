#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findSubsets(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
    ans.push_back(ds);
    for (int i = index;i < nums.size(); i++ ) {
      if( i != index && nums[i] == nums[i-1] ) continue;
      ds.push_back(nums[i]);
      findSubsets(i +1, nums, ds, ans) ;
      ds.pop_back();
    }
}
void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[0].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}
int main()
{
    vector<int> nums = {1,2,2};

    vector<vector<int>> ans;

    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);

    printVector(ans);
    return 0;
}
