#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findCombination(int index, int target, vector<int> &candidate, vector<vector<int>> &ans, vector<int> &ds) {
    if (target =0 ) {
        ans.push_back(ds);
        return;
    }
    for (int i= index; i< candidate.size(); i++) {
        if (i > index && candidate[i] == candidate[i-1]) continue;
        if (  candidate[i] > target ) break;
        ds.push_back(candidate[i]);
        findCombination( i +1, target - candidate[i], candidate, ans, ds );
        ds.pop_back();
    }
}


int main()
{
    int target = 8;
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return 0;
}
