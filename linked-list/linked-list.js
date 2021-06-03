// Node
class Node {

  constructor(value) {
    this.value = value;
    this.next = null;
  }
}


class LinkedList {

  constructor(value) {
    const newNode = new Node(value);
    this.head = newNode
    this.tail = newNode;
    this.length = 1;
  }

  append(value) {
    const newNode = new Node(value);
    this.tail.next = newNode;
    this.tail = newNode;
    this.length++;
    return this;
  }

  prepend(value) {
    const newNode = new Node(value);
    newNode.next = this.head;
    this.head = newNode;
    this.lenght++;
    return this;
  }

  remove(index) {
    const leftNode = this.traverseListToIndex(index - 1);
    const unwantedNode = leftNode.next;
    leftNode = unwantedNode.next;
    this.length--;
    return this.printList();
  }

  insert(index, value) {

    if (index >= this.length) {
      console.log("Sorry Could you please insert Correct Index");
      return ;
    }
    const newNode = new Node(value);
    const leftNode = this.traverseListToIndex(index-1);
    const rightNode = leftNode.next;
    leftNode.next = newNode;
    newNode.next = rightNode;
    this.length++;
    return this.printList();
  }

  traverseListToIndex(index) {
    if (index >= this.length) {
      console.log("There Seem to be something wrong with you guys");
      return ;
    }
    let counter = 0;

    let currentNode = this.head;
    while(counter !== index) {
      currentNode = currentNode.next;
      counter++;
    }
    return currentNode;
  }

  printList() {
    const listValueInArrays = [];
    let currentNode = this.head;
    while(currentNode !== null) {
      listValueInArrays.push(currentNode.value);
      currentNode = currentNode.next;
    }
    return listValueInArrays;
  }

}


let myLinkedList = new LinkedList(10);
myLinkedList.append(5);
myLinkedList.append(15);
myLinkedList.append(16);
myLinkedList.prepend(1);
myLinkedList.insert(2, 99);

myLinkedList.insert(20, 88);
myLinkedList.remove(2);

console.log(myLinkedList.printList());