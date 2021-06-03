class Stack  {

  constructor(value) {

    this.stackArray = [];
    if (value) {
      this.stackArray.push(value);
    }
  }

  push(value) {
    this.stackArray.push(value);
  }

  pop() {
    return this.stackArray.pop()
  }

  peek() {
    this.stackArray[this.stackArraylength - 1];
  }

  printStack() {
    return this.stackArray;
  }
}

const myStack = new Stack();
myStack.peek();
myStack.push('google');
myStack.push('udemy');
myStack.push('discord');
myStack.peek();
myStack.pop();
myStack.pop();
myStack.pop();