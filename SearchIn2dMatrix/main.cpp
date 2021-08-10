#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool findValueInMatrix(vector<vector<int>> &matrix, int target) {
  if (matrix.size() == 0) {
    return false;
  }
  int rows = matrix.size(), cols = matrix[0].size();
  int smallest = mat[0][0], largest = mat[rows - 1][cols - 1];
  if (target < smallest || target > largest)
    return false;

  int i =0, j = cols -1;
  while( i < cols && j >= 0) {
    if (matrix[i][j] == target) {
      cout << "n Found at " << i << ", " << j;
      return true;
    }
    if (matrix[i][j] > target) {
      j--;
    } else {
      i++;
    }
  }
}
bool findValueInMatrixBinarySearch(vector<vector<int>> &matrix, int target) {
  if (matrix.size() == 0) {
    return false;
  }
  int rows = matrix.size(), cols = matrix[0].size();

  int low = 0;
  int high = (rows*cols) - 1;
  while (low <= high) {
    int mid = (low + (high-low)/2);
    if ( matrix[mid/cols][mid%cols] == target) {
      return true;
    } else if ( matrix[mid/cols][mid%cols] < target) {
       low = mid +1;
    } else {
       high = mid -1;
    }

  }

  return false;
}

void printVector(vector<vector<int>> printV) {

  for(int i=0; i< printV.size(); i++) {
    for (int j =0; j < printV[i].size(); j++) {
      cout << printV[i][j] << " ";
    }
    cout<< endl;
  }
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int valueToFind  = 3;
    bool found = false;

    if  ( found =findValueInMatrixBinarySearch(matrix, valueToFind)) {
     cout << "The Target Value " <<  valueToFind << "Found" <<endl ;
    } else {
     cout << "Not Found" <<endl;
    }


    return 0;
}


