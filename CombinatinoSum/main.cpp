#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {

   if (index == arr.size()) {
       if (target == 0) {
           ans.push_back(ds);
       }
       return ;
   }

   // pick up the element at
   if (arr[index] <= target) {
       ds.push_back(arr[index]);
       findCombination(index, target- arr[index], arr, ds, ans);
       ds.pop_back();
   }

   findCombination(index + 1, target, arr, ds, ans);
}
int main()
{
    int target = 7;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ds, ans);
    return 0;
}
