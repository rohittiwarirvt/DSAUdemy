
function reverseString(sourceString) {
  const sourceStringArray = sourceString.split('');
  let reversedArray = [];

  function addToArray(array) {

    if (array.length> 0){
      reversedArray.push(array.pop());
      addToArray(array);
    }
    return ;
  }

  addToArray(sourceStringArray);
  return reversedArray.join("");

}


function reverseStringRecursive( str) {
  if (str === "") {
    return;
  } else {
    return reverseStringRecursive(str.substr(1)) + str.charAt(0);
  }

}


console.log(reverseStringRecursive('papatiwari'));
console.log(reverseString('papatiwari'));
