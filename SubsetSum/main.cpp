#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subSetSum(int index, int sum, vector<int> &arr, int NumberOfItems, vector<int> &sumSubset) {
  if (index == NumberOfItems) {
      sumSubset.push_back(sum);
      return ;
  }

  // pick the element
  subSetSum(index +1, sum + arr[index], arr, NumberOfItems, sumSubset);

  // not pick the element
  subSetSum(index +1, sum, arr, NumberOfItems, sumSubset);

}

int main()
{
    int numberOfItems = 3;
    vector<int> arr = {3, 2, 1};
    vector<int> sumSubset;
    subSetSum(0, 0, arr, numberOfItems, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    for(auto it: sumSubset) {
        cout << it << " " << endl;
    }
    return 0;
}
