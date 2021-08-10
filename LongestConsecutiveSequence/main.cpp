#include <iostream>
#include<bits/stdc++.h>
// https://leetcode.com/problems/longest-consecutive-sequence/
using namespace std;


int longestConsecutiveSubsequence(vector<int> &nums) {
    set<int> hashSet;
    for( auto num: nums) {
        hashSet.insert(num);
    }

    int longestStreak = 0;

    for( auto num: nums) {
        if (!hashSet.count(num -1)) {
            int currentNum = num;
            int currentStreak = 1;
            while (hashSet.count(currentNum + 1)) {
                currentNum+=1;
                currentStreak +=1;
            }
            longestStreak = max(currentStreak, longestStreak);
        }
    }
    return longestStreak;
}

int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    cout<< "Fount longest consequent Subsequence" << longestConsecutiveSubsequence(nums) << endl;
    return 0;
}
