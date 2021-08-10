#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void generateNextPermutation(vector<int> &input) {

    int n = input.size(), k, l;

    for(k = n-2; k >=0; k--) {

      if (input[k] < input[k+1]) {
        break;
      }
    }
    if (k < 0) {
      reverse(input.begin(), input.end());
    } else {

      for(l = n -1; l >k ; l--) {
        if (input[l] > input[k]) {
          break;
        }
      }
      swap(input[l], input[k]);
      reverse(input.begin() + k +1, input.end());
    }

}
int main()
{
    vector<int> input= {1,3,5,4,2};

    cout << "Next Permutation" << endl;
    generateNextPermutation(input);

    for(auto it: input) {
      cout << it<< " ";
    }
    return 0;
}
