#include <iostream>
 #include<bits/stdc++.h>
using namespace std;
int merge(int arr[], int left, int mid, int right);

int mergeSort(int arr[],int left,int right) {
  int inv_count = 0;
  int mid;
  if (right > left) {
    mid = (left + right )/2;

    inv_count += mergeSort(arr, left, mid);
    inv_count += mergeSort(arr, mid +1, right);

    inv_count += merge(arr, left, mid +1, right);

  }
  return inv_count;
}

int merge(int arr[], int left, int mid, int right) {
  int i, j, k;
  int inv_count =0;
  cout<< "R=" << right << "L=" <<left <<endl;
  int temp[6];
  i = left;
  j = mid;
  k = left;

  while ( (i <= mid -1) && ( j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];

      // main logic for inversino;
      inv_count = inv_count + (mid - i);
    }
  }

  while(i <= mid -1) {
    temp[k++] = arr[i++];
  }

  while(j <= right) {
    temp[k++] = arr[j++];
  }
   cout<< "Required length " << k <<endl;
   cout << "Provided length "<< right - left + 1 << endl;
  for (i= left; i <= right; i++) {
    arr[i] = temp[i];
  }
  return inv_count;

}

int main()
{

    int  arr1[] = {1, 20, 6, 4, 5};
    int arr[] = {6,1,3};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int ans = mergeSort(arr1, 0, n -1);
    cout << "Number of inversions are " << ans << endl;
    return 0;
}
