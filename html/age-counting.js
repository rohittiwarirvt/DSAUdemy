console.log("Age counting");

fetch('https://coderbyte.com/api/challenges/json/age-counting')
.then( response => response.json())
.then( data => {

  let age = findAge(data);
  console.log(`The people above the age of 50 is ${age}`);
})
.catch( (error) => {
  console.error('Error:', error);
})


function findAge(data) {
    console.log('Success:', data);
    let response = data.data.split(",",)
    let key_age_arr = [];
    for (let i=0; i < response.length; i = i +2) {
       key_age_arr.push(response.slice(i, i +2));
    }
    let key_age_obj_aggregate = key_age_arr.map((item) => {
        let obj = {};
         obj['key']= item[0].split('=')[1];
         obj['age'] =item[1].split('=')[1];
         console.log(obj)
        return obj;
    });
    let ageAbove50 = key_age_obj_aggregate.filter((item) => {
        return item.age > 50
    });

    return  ageAbove50.length;
}

// function eightQueens(strArr) {
//   let x = [],
//       y = [];
//   strArr.forEach((pos) => {
//       x.push(Number(pos.replace("(", "").replace(")", "").split(",")[0]));
//       y.push(Number(pos.replace("(", "").replace(")", "").split(",")[1]));
//   });
//   const setX = new Set(x);
//   const setY = new Set(y);
//   let flag = true;
//   let resp = "";
//   for (let i = 0; i < strArr.length; i++) {
//       for (let j = 1; j < strArr.length; j++) {
//           if (flag && (x[j] - x[i] === y[j] - y[i] || x[i] === x[j] || y[i] === y[j])) {
//               resp = (${
//                   x[i]
//               }, ${
//                   y[i]
//               });
//               flag = false;
//           }
//       }
//   }
//   if (x.length === setX && x.length === setY && !resp.length) {
//       return true;
//   } else {
//       return resp;
//   }
// }

//console.log(eightQueens(readline()));