#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
         bool isValid(string s) {
             stack<char> st;

             for (auto it: s) {
                 if ( it == '(' || it == '{' || it == '[') {
                     st.push(it);
                 } else {
                     if (st.size() == 0 ) {
                         return false;
                     }
                     char ch = st.top;
                     st.pop();

                     if (( it == ')' && ch == '(') || (it == ']' && it =='[') || (it == '}' && it =='{') {
                         continue;
                     } else return false;
                 }
             }
             return st.empty();
         }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
