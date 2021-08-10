//https://leetcode.com/problems/sort-colors/

/*
Problem Link - https://leetcode.com/problems/sort-colors/
Required Time complexity - O(n) (use only one O(n) loop to solve the problem , O(2*n) not allowed)
Required Space Complexity - O(1)

Problem in my words -  Given an array containing 0,1,2.Sort the algorithm.

Solution - Dutch national flag algorithm will be used to solve the problem in only one O(n) loop.Counting sort method will use 2 O(n) loops.So
Dutch national flag algorithm is an optimization of counting sort.

Dutch national flag algorithm will segregate 0 , 1 , 2 with the help of three pointers named as low , mid , high.

After segregation array will look like this:

Considering 1 based indexing.
index 0 to low-1 will have 0's
index low to high will have 1's
index high+1 to n-1 will have 2's
mid pointer is used to traverse the array.

if mid pointer founds 1 then it will move forward.
if mid pointer founds 0 then swap(arr[low] , arr[mid]) and move low and mid forward.
If mid pointer founds 2 then swap(arr[high] , arr[mid]) and move high backward.

Why we move mid pointer forward in case:2 after swap but we dont move mid pointer forward in case:3
Ans-
This is obvious that low pointer will only contain 0 or 1.
If low contain 0 it means that low and mid pointer are standing on same place , so left will acknowledge the 0 which he swapped with mid(that 0 is not ignored).
If Low contains 1 then see case:1 , mid has to move forward.
*/


// method 1 is to sort the array in using a sorting algorithm maybe merge sort or quick sort in nlogn time

// method 2 is to use counting sort or count the number of each value and then arrange it so that they are sorted.

// method 3 is to use dutch flag alorithm which will sort the thing in one pass
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
  int high = nums.size() -1;
  int low =0;
  int mid = 0;


  while(mid <= high) {

    switch(nums[mid]) {

      // if the element is zero swap low and mid
      case 0:
        swap(nums[mid++], nums[low++]);
        break;
      // in the element is 1 increment mmid++
      case 1:
        mid++;
        break;
      // if the element is 2 swap mid and high and decrement high--
      case 2:
        swap(nums[high--], nums[mid]);
        break;
    }
  }
}

int main()
{

    vector<int> input = {2,0,2,1,1,0};



    cout << "Sorted array is " << endl;

    sortColors(input);

    for (auto sortedArray: input) {
      cout << sortedArray << " ";
    }
    cout << endl;
    return 0;
}

