#include <iostream>
#include<bits/stc++.h>

using namespace std;

int search(vector<int>  &input_array, int target) {
    int low =0, high = input_array.size()-1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (input_array[mid] == target) {
            return mid;
        }

        // left side is sorted
        if ( input_array[low] <=input_array[mid]) {
            if (input_array[low]<=target && target <= input_array[mid]) {
                high = mid -1;
            } else {
                low = mid +1;
            }
        } else {
            if (target >= input_array[mid] && target <= input_array[high]) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
    }
    return -1
}

int main()
{

    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
