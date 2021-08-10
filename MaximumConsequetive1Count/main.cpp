#include <iostream>
#include<vector>

using namespace std;

int maximumConsecutive1Subarray(vector<int> &nums) {
    int cnt =0, maxi =0;

    for (auto it: nums) {
        if (it == 1) {
            cnt++;
        } else {
            cnt =0;
        }
        maxi= max(maxi, cnt);

    }

    return maxi;
}
int main()
{
    vector<int> nums={1,0,1,1,0,1};
    cout << maximumConsecutive1Subarray(nums) << endl;
    return 0;
}
