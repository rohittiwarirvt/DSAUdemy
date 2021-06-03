class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
  }
}


class BinarySearchTree {
  constructor () {
    this.root = null;
  }

  insert(value) {
    const newNode = new Node(value);
    if (this.root == null) {
      this.root = newNode;
    } else {
      let currentNode = this.root;
      while ( true) {
        if (value > currentNode.value ) {

          if (!currentNode.right) {
            currentNode.right = newNode;
            return ;
          }

          currentNode = currentNode.right;
        }
        if ( value < currentNode.value) {

          if (!currentNode.left) {
            currentNode.left = newNode;
            return
          }
          currentNode = currentNode.left

        }
      }
    }
  }

  lookup(value) {
    let currentNode = this.root;
    while (currentNode) {
      if (currentNode.value === value) {
        return currentNode;
      } else if (value < currentNode.value) {
        currentNode = currentNode.left;
      } else if (value > currentNode.value) {
        currentNode = currentNode.right;
      }

    }
    return 'Value not Fount ' + value;
  }

  // this function call removeNode;
  remove(value) {
    this.root = this.removeNode(this.root, value);
  }

  // recursisve function to insert new value in binary search treee;
  removeNode(current, value) {

    // base case if the tree is empty.
    if (current === null) {
      return
    }

    // when the value is same as the current value, this is the node to be deleted.
    if ( current.value === value) {

       // For case 1 & 2, node without child or   with one child.
       if (current.left === null && current.right === null) {
        return null;
       } else if (current.left === null) {
         return current.right;
       } else if (current.right === null) {
         return current.left;
       } else {

        // node with two children, get the inorder successor,
        // smallest in the right subtree.
         let tempNode = this.kthSmallestNode(current.right);
            current.value = tempNode.value;

        // delete the inorder successor.
         current.right = this.removeNode(current.right, tempNode.value);

         return current;
       }

       // recur down the tree.
    }  else if ( value < current.value  ) {

      current.left = this.removeNode(current.left, value);
      return current;
    } else if (value > current.value) {
      current.right = this.removeNode(current.right, value);
      return current;
    }
  }

  kthSmallestNode(node) {
    while(!node.left === null) {
      node = node.left;
    }
    return node;
  }

  breadthFirstSearch() {
    let list = [];
    let queue = [];
    let currentNode;
    if (this.root !== null) {
      currentNode = this.root;
    }
    queue.push(currentNode);
    while(queue.length > 0) {
      currentNode = queue.shift();
      list.push(currentNode.value);
      if(currentNode.left) {
        queue.push(currentNode.left);
      }

      if (currentNode.right) {
        queue.push(currentNode.right);
      }
    }

    return list;
  }

  breadthFirstSearchR(queue, list) {
    if(!queue.length) {
      return list;
    }

    let currentNode = queue.shift();
    list.push(currentNode.value);
    if (currentNode.left) {
      queue.push(currentNode.left);
    }

    if (currentNode.right) {
      queue.push(currentNode.right);
    }
    this.breadthFirstSearchR(queue, list);
  }

  dftPreOrder() {
    this.traversePreOrder(this.root, []);
  }

  dftInOrder() {
    this.traverseInOrder(this.root, []);
  }

  dftPostOrder() {
    this.traversePostOrder(this.root, []);
  }

  travserPreOrder(node, list) {
    list.push(node.value);
    if (node.left) {
      this.traversePreOrder(node.left, list);
    }
    if (node.right) {
      this.traversePreOrder(node.right, list);
    }
    return list;
  }

  traverseInOrder(node, list) {
    if( node.left) {
      this.traverseInOrder(node.left, list);
    }
    list.push(node.value);
    if (node.right) {
      this.traverseInOrder(node.right, list);
    }
    return list;
  }

  traversePostOrder(node, list) {
    if ( node.left) {
      this.traversePostOrder(node.left, list);
    }

    if ( node.right) {
      this.traversePostOrder(node.right, list);
    }

    list.push(node.value);
    return list;
  }
}


//     9
//  4     20
//1  6  15  170

function traverse ( node) {
  const tree = { value: node.value};
  tree.left = node.left === null ? null  : traverse(node.left);
  tree.right = node.right === null ? null  : traverse(node.right);
  return tree;
}

const tree = new BinarySearchTree();
tree.insert(9)
tree.insert(4)
tree.insert(6)
tree.insert(20)
tree.insert(170)
tree.insert(15)
tree.insert(1)
// tree.remove(170)
// console.log(tree);
// console.log(JSON.stringify(traverse(tree.root)));

console.log('BFS', tree.breadthFirstSearch());
console.log('BFS', tree.breadthFirstSearchR([tree.root], []))
console.log('DFSpre', tree.dftPreOrder());
console.log('DFSin', tree.dftInOrder());
console.log('DFSpost', tree.dftPostOrder());