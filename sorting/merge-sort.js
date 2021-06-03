const input = [99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0];

function mergeSort(input) {

  const length = input.length;

  if ( length === 1) {
    return input;
  }

  // Split Array into right and left.
  const middle = Math.floor(length/2);
  const left = input.slice(0, middle);
  const right = input.slice(middle);

  return merge(
    mergeSort(left),
    mergeSort(right)
  );

}


function merge(left, right) {

  let results = [] ;
  let leftIndex =0 ;
  let rightIndex=0 ;

  while( leftIndex < left.length &&  rightIndex < right.length ) {

    if (left[leftIndex] < right[rightIndex]){
      results.push(left[leftIndex]);
      leftIndex++;
    } else {
      results.push(right[rightIndex]);
      rightIndex++;
    }
  }

  // console.log('left', left);
  // console.log('right', right);
  return results.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
}


const answer = mergeSort(input);
console.log(answer);