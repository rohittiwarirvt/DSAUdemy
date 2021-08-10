#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


void mergeWithLastFirst(int arr1[], int arr2[], int n, int m) {
  int i=n-1, j=0;
  while(i >=0 && j <= m-1) {
    if (arr1[i] > arr2[j] ) {
      swap(arr1[i], arr2[j]);
      i--;
      j++;
    }
    else
      break;
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

int nextGap(int gap) {
  if (gap <= 1 )
    return 0;

  return (gap /2)  + (gap %2);

}
void mergeWithGap(int *a1, int *a2, int n, int m) {
   int i, j , gap = n +m;

   for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {

     // comparing elements in first array
     for(i =0 ; i + gap < n; i++) {
      if (a1[i] > a1[i+ gap]) {
        swap(a1[i], a1[i+gap]);
      }
     }

     // compariing element between two arrays
     for (j  = gap> n ? gap - n: 0; i < n && j < m; i++, j++) {
       if (a1[i] > a2[j]) {
        swap(a1[i], a2[j]);
       }
     }

     // comparing element in second array;
     if ( j < m) {
        for (j=0; j  + gap < m; j++) {
          if (a2[j] > a2[j+gap]) {
            swap(a2[j], a2[j+gap]);
          }
        }
     }

   }
}

 // Utility function to print contents of an array
void printArray(int a1[], int n) {
  for (int i; i < n; i++) {
     printf("%d ", a1[i]);
  }
}


// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
void mergeInPlace(int a1[], int a2[], int n, int m) {

    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
  for(int i =0; i< n; i++) {

      // compare the current element of `X[]` with the first element of `Y[]`
    if (a1[i] > a2[0]) {
      swap(a1[i], a2[0]);
      int first = a2[0];
       // move `Y[0]` to its correct position to maintain the sorted
      // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
      int k;
      for(k=1; k < m && a2[k] < first; k++ ) {
        a2[k-1] = a2[k];
      }
      a2[k-1] = first;
    }

  }
}

int main()
{
    int a1[] = {10, 27, 38, 43, 82};
    int a2[] = {3, 9};

    int n = sizeof(a1)/sizeof(a1[0]);
    int m = sizeof(a2)/ sizeof(a2[0]);
    //mergeWithLastFirst(arr1, arr2, n, m);

    mergeWithGap(a1, a2, n, m);

    //mergeInPlace(a1, a2, n, m);
    printf("First Array:");
    printArray(a1, n);
    printf("\nSecond Array:");
    printArray(a2, m);


    return 0;
}
