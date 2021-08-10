#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> st;
    int leftSmall[n], rightSmall[n];
    for(int i=0; i < n; i++) {
      while(!stack.empty() && heights[st.top()] >= heights[i])   {
          st.pop();
      }

      if(st.empty()) leftSmall[i] =0;
      else leftSmall[i] = st.top() +1;
      st.push(i);
    }

    // clear the stack to be re-used
    while(!st.empty()) st.pop();

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if(st.empty()) rightSmall[i] = n -1;
        else rightSmall[i] = st.top() -1;

        st.push(i);
    }
}
int main()
{

    vector<int> heights = {2,1,5,6,2,3};
    return 0;
}
