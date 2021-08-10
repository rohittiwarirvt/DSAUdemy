#include <iostream>
#include<vector>

using namespace std;

int removeDuplicatesFromSortedArray(vector<int> &input) {
    if (input.size() == 0) return 0;

    int i =0;

    for (int j =1; j < input.size(); j++) {
        if (input[j] != input[i]) {
            i++;
            input[i] = input[j];
        }
    }

    return i +1;
}
int main()
{
    vector<int> input = {0,0,1,1,1,2,2,3,3,4};

    cout << removeDuplicatesFromSortedArray(input) << endl;
    return 0;
}
