//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined

function firstOccurenceOfP1(arr) {

  for (let i =0; i < arr.length; i++) {
    for (let j=i+1; j < arr.length ; j++) {

      if ( arr[i] === arr[j]) {
        return arr[i];
      }
    }
  }
  return undefined;
}

console.log(firstOccurenceOfP1([2,5,1,2,3,5,1,2,4]));
console.log(firstOccurenceOfP1([2,1,1,2,3,5,1,2,4]));
console.log(firstOccurenceOfP1([2,3,4,5]));


function firstOccurenceOfP2(arr) {
  const hashMap = {};
  for (let i =0; i< arr.length; i++) {
    if( hashMap[arr[i]] === 'udefined') {
      hashMap[arr[i]] = true;
    } else {
      return arr[i];
    }
  }
}