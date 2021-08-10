#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[0].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}

vector<vector<int>> threeSum(vector<int> &nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i =0; i < nums.size() -2; i++) {
        if ( i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            int low = i +1, high= nums.size() -1, sum = 0 - nums[i];
            while(low < high) {
                if ( nums[low] + nums[high] == sum) {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[low]);
                    triplet.push_back(nums[high]);
                    res.push_back(triplet);

                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high -1]) high--;

                    low++;
                    high--;
                } else if (nums[low] + nums[high] <sum) {
                    low++;
                } else {
                    high--;
                }
            }

        }

    }

    return res;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    printVector(res);
    cout << "Hello world!" << endl;
    return 0;
}
