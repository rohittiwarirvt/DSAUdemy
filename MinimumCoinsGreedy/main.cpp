#include <iostream>
#include<vector>
using namespace std;

void findMin(int targetChange) {
    int denominations[] = {1, 2,5,10,20,50,100,500,1000};
    int n = 9;

    vector<int> ans;
    for (int i= n-1; i > 0; i--) {
        while(targetChange >= denominations[i]) {
            targetChange-=denominations[i];
            ans.push_back(denominations[i]);
        }
    }

    for (auto it: ans) {
        cout << it << " ";
    }
}
int main()
{
    cout << "out put \n" << endl;
    findMin(49)  ;
    return 0;
}
