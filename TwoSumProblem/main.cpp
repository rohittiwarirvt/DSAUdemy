#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> ans;
  unordered_map<int, int> mpp;
  for(int i =0; i< nums.size(); i++) {
    if(mpp.find(target - nums[i]) != mpp.end()) {
      ans.push_back(mpp[target -nums[i]]);
      ans.push_back(i);
      return ans;
    }
    mpp[nums[i]] = i;
  }
  return ans;
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    cout << "Found value at "<<endl;
    vector<int> result = twoSum(nums,target);
    for(auto it: result) {
      cout << it << " " ;
    }
    return 0;
}
