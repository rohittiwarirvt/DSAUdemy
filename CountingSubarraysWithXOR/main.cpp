#include <iostream>
#include<bits/stdc++.h>

// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

using namespace std;

int countingSubarrayWithXor(vector<int> &input, int target) {
  map<int, int> freq;
  int cnt = 0;
  int xorr = 0;

  for (auto it: input) {
    xorr = xorr^it;
    if (xorr == target) {
      cnt++;
    }
    if (freq.find(xorr^target)!= freq.end()) {
      cnt += freq[xorr ^ target];
    }
    freq[xorr] += 1;
  }
  return cnt;
}
int main()
{
    vector<int> input = {4, 2, 2, 6, 4};
    int target = 6;
    cout << countingSubarrayWithXor(input, target) << endl;

    return 0;
}
