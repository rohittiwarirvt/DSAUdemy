#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;



bool comparator(int x, int y) {
  return x > y;
}

void vectorDemo() {
  vector<int> A = { 11, 12, 13, 14};
  cout << A[1] << endl;

  sort(A.begin(), A.end()) ; //O(N log(N))
  // 2,3, 11, 14

  bool present = binary_search(A.begin(), A.end(), 3);  // true
  present = binary_search(A.begin(), A.end(), 4); //false

  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  present = binary_search(A.begin(), A.end(), 100); //true;
  cout << present << endl;

  A.push_back(123);

  auto it = lower_bound(A.begin(), A.end(), 100); //>=
  vector<int>::iterator it1 = upper_bound(A.begin(), A.end(), 100); // >

  cout << *it << " " << *it1 << endl;
  //cout << it1 - it << endl;

  vector<int>::iterator it2;
  sort(A.begin(), A.end(), comparator);
  for (it2 = A.begin(); it2 != A.end(); it2++) {
    cout << *it2 << " ";
  }

  for (auto x: A)  {
    cout << x << " - ";
  }

}

void setDemo() {
   set<int> S;
   S.insert(4);
   S.insert(7);
   S.insert(10);
   S.insert(6);

   for (int x: S) {
    cout << x << " ";
   }

   auto it = S.lower_bound(7);
   auto it1 = S.upper_bound(7);
   cout <<" LB" << *it << endl;
   cout <<" UP" << *it1 << endl;

   auto it2 = S.find(10);

   if (it2 == S.end()) {
    cout << "Value not found" << endl;
   } else {
    cout << "Value found bro " << *it2 << endl;
   }
}

void mapDemo() {
  map<int, int> my_map;

  my_map[1] = 2;
  my_map[3] = 5;
  my_map[4] = -2;
  my_map[5] = 9;
  my_map[12] = 12;

  map<char, int> my_string_map;

  string x = "rohit tiwari";

  for (char k: x) {
    my_string_map[k]++;
  }

  cout << my_string_map['r'] << " " << my_string_map['h'] << endl;
}

void pairDemo() {

  set<pair<int, int>> S;

  S.insert({401, 450});
  S.insert({10, 20});
  S.insert({2, 3});
  S.insert({30, 400});

  int point = 12;

  auto it = S.upper_bound({point, INT_MAX});
  if (it == S.begin()) {

    cout << "The given interval is not lying under any interval" << endl;
  }
  it--;

  pair<int, int> current = *it;
  if ( current.first <= point && current.second >= point) {
     cout << "The given interval is found under" << current.first << "and" << current.second << endl;
   } else {
     cout << "The given interval is not lying under any interval" << endl;
  }
}
int main()
{

  pairDemo();
}
