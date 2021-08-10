#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  deque<int> dq;
  vector<int> ans;
  for(int i=0;i< nums.size(); i++) {
      if(!dq.empty() && dq.front() == i-k) {
          dq.pop_front();
      }
      while(!dq.empty() && nums[dq.back()] <= nums[i]) {
          dq.pop_back();
      }

      dq.push_back(i);
      if(i>= k-1) ans.push_back(nums[dq.front()]);
  }

  return ans;
}

int main()
{
   vector<int> input = {1,3,-1,-3,5,3,6,7};
   int k = 3;

   vector<int> result;
   result = maxSlidingWindow(input, k);
   for(auto it: result) {
       cout<< it << " ";
   }
  return 0;
}
