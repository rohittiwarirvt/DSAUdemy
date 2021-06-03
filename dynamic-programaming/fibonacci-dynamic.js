
let calculationDynamicProgramming = 0;
let calculationRecursiveProgramming = 0;
let calculationForIterativeProgramming = 0;


function fibonacciNormal(indextoFind) {
  calculationRecursiveProgramming++;
  if ( indexToFind < 2) {
    return indexToFind;
  }
  return fibonacciNormal(indexToFind -2) + fibonacciNormal(indexToFind - 1);
}


function fibonacciDynamicProgrammingOne() {
    let cache  = {};
    return function fib(indexToFind) {
      calculationDynamicProgramming++;
      if ( cache[indexToFind]) {
        return cache[indexToFind]
      } else{
        if ( indexToFind < 2) {
          return indexToFind;
        } else {
          cache[indexToFind] = fib(indexToFind-2) + fib(indexToFind - 1);
          return cache[indexToFind];
        }
      }
    }
}



function fibonacciIterativeApproach(indextoFind) {
  let array = [0,1];
  calculationForIterativeProgramming++;
  for (let i = 2 ; i<= indexToFind; i++) {
    array.push(array[i-2] + array[i-1]);
    calculationForIterativeProgramming++;
  }

  return array[indexToFind];
}

console.log('Slow', fibonacciNormal(35))
console.log('we did ' + calculationRecursiveProgramming + ' calculations');

console.log('DP', fibonacciDynamicProgrammingOne()(100));
console.log('we did ' + calculationDynamicProgramming + ' calculations');

console.log('DP2', fibonacciIterativeApproach(100));
console.log('we did ' + calculationForIterativeProgramming + ' calculations');

