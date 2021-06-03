const input = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];


function insertionSort(input) {
  let length = input.length;
  for ( let i =0; i < length; i++) {
    if ( input[i] < input[0]) {
      input.unshift(input.splice(i,1)[0]);
    } else {
      if (input[i] < input[i-1]) {
        for (let j = 1; j < i ; j++) {
          if ( input[i] >= input[j-1] && input[i] < input[j]) {
            input.splice(j, 0, input.splice(i, 1)[0])
          }
        }
      }
    }

  }

  return input;
}

insertionSort(input);