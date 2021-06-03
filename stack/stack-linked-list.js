class Node {

  constructor(value) {
    this.value = value;
    this.next= null;
  }
}


class Stack {
  constructor(value) {
    this.top = new Node(value);
    this.length = 1;
  }

  push(value) {
    const newNode = new Node(value);
    newNode.next = this.top;
    this.top = newNode;
    this.length++;
    this.printStack();
  }

  pop() {
    if (this.length == 0) {
      console.log('The stack is empty!.');
      return '';
    }
    const nodeToPop = this.top;
    this.top = nodeToPop.next;
    this.length--;
    this.printStack();
    return nodeToPop;
  }

  peek() {
    return this.top;
  }

  printStack()  {
    let currentNode = this.top;
    let results = []
    while(currentNode !== null) {
      results.push(currentNode.value);
      currentNode = currentNode.next;
    }
    return results;
  }
}

const stack = new  Stack(1);
stack.push('google');
stack.push('udemy');
stack.push('discord');
console.log(stack.printStack());
 stack.peek();

stack.pop();
stack.pop();
stack.pop();
console.log(stack.printStack());
stack.pop();
stack.pop();
console.log(stack.printStack());