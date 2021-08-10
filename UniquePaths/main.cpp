#include <iostream>
#include<vector>
using namespace std;

// Optimal approach  O(n-1) or O(m-1)
int uniquePaths(int m, int n) {
   //number of steps needed
   int N = m + n -2;
   // numer rows or columsn for m+n-2Cm-1
   int r = n -1;
   double res =1;

   for( int i=1; i<=r; i++) {
    res = res*(N - r +i)/i;

   }
   return (int)res;

}

int uniquePathRecursionWithoutDp(int i, int j, int m, int n ) {
  if ( i == (m-1) && j == (n-1)) return 1;
  if ( i>=m || j >= n) return 0;
  else return uniquePathRecursionWithoutDp(i+1,j, m, n ) + uniquePathRecursionWithoutDp(i, j+1, m, n);
}

int uniquePathRecursionWithDp(int i, int j, int m, int n , vector<vector<int>> &dp){
  if ( i == (m-1) && j == (n-1)) return 1;
  if ( i>=m || j >= n) return 0;
  if (dp[i][j] != -1){
   return dp[i][j];
  } else {
    return dp[i][j] = uniquePathRecursionWithDp(i +1,j,m,n,dp) + uniquePathRecursionWithDp(i,j +1,m,n,dp);
  }
}
int main()
{
    vector<vector<int>> dp(7,vector<int>(3, -1));

    int m =7, n=3;
    cout << "Unique path optimal Approach!" << endl;
    cout << uniquePaths(m,n) << endl;
    cout << "Unique path best Approach!" << endl;
    cout << uniquePathRecursionWithDp(0,0, m,n,dp) << endl;
    cout << "Unique path worst Approach!" << endl;
    cout << uniquePathRecursionWithoutDp(0,0,m,n) << endl;
    return 0;
}
