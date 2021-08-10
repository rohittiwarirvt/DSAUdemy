#include <iostream>
#include<bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2) {
    if ( m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else if (m1.pos< m2.pos) return true;
    return false;
}

void maxMeetings(int startTime[], int endTime[], int meetingsCount) {

    struct meeting meet[meetingsCount];

    for (int i =0 ; i< meetingsCount ; i++) {
      meet[i].start = startTime[i];
      meet[i].end = endTime[i];
      meet[i].pos = i +1;
    }

    sort(meet, meet +meetingsCount, comparator);

    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);
    for ( int i =1 ;i<  meetingsCount; i++) {
        if (limit < meet[i].start){
            limit = meet[i].start;
            ans.push_back(meet[i].pos);
        }
    }
    for (int it: ans) {
        cout << it << " ";
    }
}
int main()
{
    int meetingsCount = 6;
    int startTime[] = { 1, 3, 0, 5, 8, 5};
    int endTime[] = {2, 4, 6, 7, 9, 9};

    maxMeetings(startTime, endTime, meetingsCount);

    return 0;
}
