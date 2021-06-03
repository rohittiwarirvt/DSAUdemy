

function factorial(number) {
  if (number == 0) {
    return 1
  }
  result = 1;
  for (let i = 1 ; i <= number ; i++) {
    result = i * result;
  }
  return result;
}

function factorialRecursive(number) {
  if (number == 0) {
    return 1;
  }

  return number *factorialRecursive(number - 1);
}
console.log(factorial(5));
console.log(factorial(11));
