const input = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function quickSort(array, left, right) {
  debugger;
  let partitionIndex;
  let pivot ;
  if (left < right) {
    pivot = right;
    partitionIndex = partition(array, pivot, left, right);

    quickSort(array, left, partitionIndex - 1);

    quickSort(array, partitionIndex + 1, right);
  }


  return array;

}



function partition(array, pivot, left, right) {
  debugger;
  const pivotValue = array[pivot];
  let partitionIndex = left;
  for (let i = left ; i < right; i++) {
    if ( array[i] < pivotValue) {
      swap(array, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap( array, right, partitionIndex);
  return partitionIndex;
}


function swap(array, firstIndex, secondIndex) {
  let temp;
  temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}


//Select first and last index as 2nd and 3rd parameters

const output = quickSort(input, 0, input.length -1 );
console.log(output);