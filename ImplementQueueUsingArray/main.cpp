#include <iostream>

using namespace std;

int pop() {
  if( cnt == 0) {
      return -1;
  }
  array[front % N] = -1;
  front++;
  cnt--;
}

int top() {
    if (cnt == 0) -1;
    return array[front % N];
}

int push(int value) {
    if (cnt == N) return -1;
    array[N % rear] = value;
    rear++;
    cnt++;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
