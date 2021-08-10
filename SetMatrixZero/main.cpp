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

void setZero(vector<vector<int>> &matrix) {
  int col1 = 1, rows = matrix.size(), columns = matrix[0].size();

  for (int i =0 ; i< rows; i++) {
    if (matrix[i][0] == 0) {
        col1 = 0;
    }
    for (int j = 1; j < columns; j++) {
        if (matrix[i][j] == 0 ) {
          matrix[i][0] = matrix[0][j]= 0;
        }
    }
  }

  for(int i = rows -1 ; i >= 0; i--) {
    for(int j = columns - 1; j >=1; j--) {
      if ( matrix[i][0] ==0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col1 == 0) matrix[i][0] = 0;
  }

}
int main()
{
    vector<vector<int>> matrix =  {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "The matrix before modification" << endl;
    printVector(matrix);
    setZero(matrix);
    cout << "The Matrix after modification" << endl;
    printVector(matrix);

    return 0;
}
