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

void rotateMatrix(vector<vector<int>> &matrix) {
   int rows = matrix.size(), cols = matrix[0].size();
   for(int i =0; i< rows; i++) {
    for (int j =0 ; j< i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
   }

   for (int i=0; i< rows; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
   }

}
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "Original matrix " << endl;
    printVector(matrix);
    rotateMatrix(matrix);
    cout << "Rotated Matrix" << endl;
    printVector(matrix);
    return 0;
}
