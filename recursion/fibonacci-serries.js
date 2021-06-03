// Given a number N return the index value of the Fibonacci sequence, where the sequence is:

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...
// the pattern of the sequence is that each value is the sum of the 2 previous values, that means that for N=5 → 2+3

//For example: fibonacciRecursive(6) should return 8


function fibonacciIterative(indexToFind) {
  let array = [0, 1];

  for (let i =2; i <= indexToFind; i++) {
    array.push(array[i-1] + array[i-2]);
  }

  return array[indexToFind];
}

function fibonacciRecursive(indexToFind) {
  if (indexToFind < 2) {
    return indexToFind;
  }

  return fibonacciRecursive(indexToFind - 2) + fibonacciRecursive(indexToFind -1);
}


console.log(fibonacciRecursive(17));
console.log(fibonacciIterative(17));