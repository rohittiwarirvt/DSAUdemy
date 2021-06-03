const input = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function selectionSort(input) {
  let length = input.length;
  for ( let i =0; i < length; i++) {
     // set current index as minimum
    let min = i;
    for (let j = i +1;j < length; j++) {
      if (input[j] < input[min]) {
      //update minimum if current is lower that what we had previously
          min = j;
      }
    }

    // swap minimum and first value
    temp = input[min];
    input[min] = input[i];
    input[i] = temp;
  }
  return input;
}

selectionSort(input);
console.log(input);