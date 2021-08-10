#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums) {
  int n = nums.size();
  stack<int> st;
  vector<int> nge(n, -1);
  for (int i = 2*n-1; i>=0 ; i--) {
      while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
      }
      if ( i < n) {
          if (!st.empty())  {
              nge[i] = st.top();
          }
      }
      st.push(nums[i%n]);
  }
  return nge;
}

int main()
{
    vector<int> nums  = {1,2,3,4,3};
    vector<int> results ;

    results = nextGreaterElement(nums);
    for (auto it: results) {
      cout << it << endl;
    }

    return 0;
}
