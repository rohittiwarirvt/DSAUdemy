#include <iostream>

using namespace std;
Struct Item {
    int value;
    int weight;
}

double fractionalKnapsack(int BoxCapacity, Item arr[], int numberOfItems) {
    sort(arr, arr +numberOfItems, comparator);

    int curWeight = 0;
    double finalValue = 0;
    for (int i =0; i< numberOfItems; i++) {
        if ( curWeight + arr[i].weight <= BoxCapacity) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remainingWeight = BoxCapacity - curWeight;
            finalValue+= (arr[i].value/(double)arr[i].weight)*(double)remain;
            break;
        }

    }

    return finalValue;
}
int main()
{

    return 0;
}
