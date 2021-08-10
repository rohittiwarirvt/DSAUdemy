#include <iostream>
#include<vector>
using namespace std;

int trapRainwater(vector<int> &height) {
  int n = height.size();
  int left = 0;
  int right = n-1;
  int res = 0;
  int leftMax=0, rightMax=0;

  while (left < right) {

      if (height[left] <= height[right]) {
          if (leftMax <= height[left]) {
              leftMax = height[left];
          } else {
              res += leftMax - height[left];
          }
        left++;
      } else {
          if (rightMax <= height[right]) {
              rightMax = height[right];
          } else {
              res += rightMax - height[right];
          }
          right--;
      }

  }
  return res;
}
int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped rainwater" << endl;
    cout<< trapRainwater(height) << endl;
    return 0;
}
