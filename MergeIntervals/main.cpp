/*
https://leetcode.com/problems/merge-intervals/
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &input) {
  vector<vector<int>> mergedIntervals ;

  if (input.size() == 0) {
    return mergedIntervals;
  }
  sort(input.begin(), input.end());
  vector<int> tempInterval = input[0];

  for (auto it: input) {
    if (tempInterval[1] >= it[0]) {
      tempInterval[1] = max(tempInterval[1], it[1]);
    } else {
      mergedIntervals.push_back(tempInterval);
      tempInterval = it;
    }

  }

  mergedIntervals.push_back(tempInterval);
  return mergedIntervals;
}
void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[0].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}
int main()
{
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = merge(input);
    cout<< "Result is " << endl;
    printVector(result);
    cout << endl;
    return 0;
}
