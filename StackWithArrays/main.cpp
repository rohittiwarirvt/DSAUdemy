#include <iostream>

using namespace std;
int array_size[10];
int top = -1;
void push(int value) {
    array_size[++top] = value;
}

void pop() {
    return array_size[top--]

}

int top() {
   return top;
}
bool isEmpty() {
    if (array_size.size() == 0) {
        return true;
    }
    return false;
}
int main()
{


    cout << "Hello world!" << endl;
    return 0;
}
