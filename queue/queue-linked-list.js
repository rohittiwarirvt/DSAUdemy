class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}


class Queue {

  constructor(value) {
    const newNode = new Node(value);
    this.front = newNode;
    this.tail = this.front;
    this.length = 1;
  }

  enqueue() {
    const newNode = new Node(value);
    this.tail.next = newNode;
    this.tail = newNode;
    this.length++;
    this.printQueue();
    return this;
  }

  dequeue() {
    if (this.length == 0 ) {
      console.log('Queue is empty. Invalid Operation.');
      return ;
    }
    const nodeToDequeue = this.front;
    this.front = nodeToDequeue.next;
    this.length--;
    this.printQueue();
    return nodeToDequeue;

  }

  printQueue() {
    let currentNode = this.front;
    let results = [];
    while( currentNode !== null) {
      results.push(currentNode);
      currentNode = currentNode.next;
    }
    return results;
  }
}


const myQueue = new Queue('Jyoti');
myQueue.peek();
myQueue.enqueue('Joy');
myQueue.enqueue('Matt');
myQueue.enqueue('Pavel');
myQueue.peek();
myQueue.dequeue();
myQueue.dequeue();
myQueue.dequeue();
myQueue.peek();