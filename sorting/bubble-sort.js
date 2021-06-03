const input = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function bubbleSort(input) {
  let length = input.length;
  for ( let i=0; i < length; i++) {
    for (let j =0; j < length; j++ ) {
      if ( input[j] > input[j+1]) {
        let temp = input[j];
        input[j] = input[j + 1];
        input[j+1] = temp;
      }
    }
  }
}