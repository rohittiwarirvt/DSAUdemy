#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[i].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}

vector<vector<int>> pascalTriangleGenerate(int numRows) {

    vector<vector<int>> r(numRows);

    for(int i=0;i< numRows; i++) {
      r[i].resize(i + 1);
      r[i][0]= r[i][i] = 1;
      for(int j=1; j< i; j++) {
        r[i][j] = r[i-1][j-1] + r[i -1][j];
      }
    }

    return r;

}
int main()
{
    int numRows = 5;
    vector<vector<int>> result = pascalTriangleGenerate(numRows);
    printVector(result);
    return 0;
}
