#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparater(Job arr1, Job arr1) {
  return (arr1.profit > arr2.profit);
}
pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr+n, comparater);

    int maxiDeadline = arr[0].deadline;
    for (int i =1; i< n; i++) {
        maxiDeadline = max(maxi, arr[i].deadline);
    }

    int arrOfDeadlinesSlot[maxiDeadline + 1];
    for (int i=0; i<= maxiDeadline; i++) {
        arrOfDeadlinesSlot[i] =-1;
    }

    int countJobs =0; jobProfit=0;

    for (int i =0; i < n ; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (arrOfDeadlinesSlot[j] == -1) {
                arrOfDeadlinesSlot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(countJobs, jobProfit);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
