#include <iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &array_books, int pages, int number_of_students) {
    int cnt = 0;
    int sumAllocated = 0 ;
    for (int i = 0; i < array_books.size(); i++) {
        if ( sumAllocated + array_books[i] > pages) {
            cnt++;
            sumAllocated = array_books[i];
            if (sumAllocated > pages) return false;
        } else {
            sumAllocated += array_books[i];
        }
    }
    if (cnt < number_of_students) return true;
    return false;
}

int allocateBooks(vector<int> &array_books, int number_of_students) {
    if( number_of_students > array_books.size()) return -1;
    int low = array_books[0];
    int high = 0;
    for (int i = 0; i < array_books.size(); i++) {
        high += array_books[i];
        low = min(low, array_books[i]);
    }

    int res = -1;

    while (low <= high) {
        int mid = (low + high) >> 1;
        if (isPossible(array_books, mid, number_of_students)) {
            res = mid;
            high = mid -1;
        } else {
            low = mid +1;
        }
    }
    // return res -> this is also correct
    return low;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
