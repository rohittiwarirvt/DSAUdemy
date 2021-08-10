#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &inputs) {
    int slow = inputs[0];
    int fast = inputs[0];

    do {
       slow = inputs[slow];
       fast = inputs[inputs[fast]];
    } while( slow != fast) ;

    fast = inputs[0];

    while(slow != fast) {
      slow = inputs[slow];
      fast = inputs[fast];
    }
    return slow;
}

int main()
{
    vector<int> input = {1,3,4,2,2};

    int result  = findDuplicate(input);
    cout << "Result is  " << result << endl;
    return 0;
}
