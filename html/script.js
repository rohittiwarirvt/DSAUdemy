function mergeSort(arr, left, right) {
  //debugger;
  let inv_count = 0;
  let mid;
  if (right > left) {
    mid = Math.floor((left + right )/2);

    inv_count += mergeSort(arr, left, mid);
    inv_count += mergeSort(arr, mid +1, right);

    inv_count += merge(arr, left, mid +1, right);

  }
  return inv_count;
}

function merge(arr, left, mid, right) {
  //debugger;

  let i, j, k;
  let inv_count =0;
  let temp = [];
  i = left;
  j = mid;
  k = left;

  while ( (i <= mid -1) && ( j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];

      // main logic for inversino;
      inv_count = inv_count + (mid - i);
    }
  }

  while(i <= mid -1) {
    temp[k++] = arr[i++];
  }

  while(j <= right) {
    temp[k++] = arr[j++];
  }

  for (let i= left; i <= right; i++) {
    arr[i] = temp[i];
  }
  return inv_count;

}


arr1  = [1, 20, 6, 4, 5];




