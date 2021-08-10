#include <iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices) {
  int miniPrice = INT_MAX;
  int maxProfit = 0;
  for ( auto it: prices) {
    miniPrice = min(it, miniPrice);
    maxProfit = max(it - miniPrice, maxProfit);
  }
  return maxProfit;
}
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit is " << endl;
    cout << maxProfit(prices)<< endl;
    return 0;
}
