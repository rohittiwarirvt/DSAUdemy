#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> AllPossibleString(string s) {
    int n = s.size();
    vector<string> answer;

    for (int num = 0; num < ( 1<< n); num++) {
        string sub = "";
        for (int i =0; i < n; i++) {
            if (num & (1 << i)) {
                sub += s[i];
            }
        }
        if (sub.size() > 0) {
            answer.push_back(sub);
        }

    }
    sort( answer.begin(), answer.end());
    return answer;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
