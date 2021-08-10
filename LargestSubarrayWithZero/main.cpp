#include <iostream>
#include<bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
using namespace std;

int largestSubarrayWithZero(int input[], int n) {

    unordered_map<int, int> mpp;
    int maxi =0 ;
    int sum = 0;
    for (int i =0 ; i< n-1; i++) {
        sum += input[i];
        if ( sum == 0) {
            maxi = i +1;
        } else {
            if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            } else {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int input[] = {15,-2,2,-8,1,7,10,23};
    int n = sizeof(input)/ sizeof(input[0]);
    cout << largestSubarrayWithZero(input, n) << endl;
    return 0;
}
