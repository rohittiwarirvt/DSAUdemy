// To Inherit without Es6 class syntax

function Person(firstname, lastname, age, hobbies) {
  this.name = firstname + lastname;
  this.age = age;
  this.hobbies = hobbies;
}


Person.prototype.introduction = function() {
  debugger;
  console.log(`My name is ${this.name} and i am ${this.age} old. My hobbies Are ${this.hobbies.join(',')}`);
}

Person.prototype.demographiscs = function() {
  console.log(`Hi I am just a kid with ${this.age}`);
}


function Student(firstname, lastname, age, hobbies, standard, subject) {
  Person.call(this, firstname, lastname, age, hobbies);
  this.standard = standard;
  this.subject = subject;
}


Student.prototype = Object.create(Person.prototype);

Object.defineProperty(Student.prototype, 'constructor', {
  value:Student,
  enumerable: false, // so that it does not appear in 'for in' loop
  writable: true });

//Student.prototype.constructor = Student;
Student.prototype.qualification = function() {
  console.log(`Iam in ${this.standard} standard and my majars are in ${this.subject}`);
}

const rohit = new Person('rhit',' vinod', 12, ['gym','trek', 'problem solving', 'travel']);
rohit.introduction();
rohit.demographiscs();
const person = new Student('rahult', 'tiwari', 29, ['pubg','work'], '5th', 'commerce');

person.introduction();
person.demographics();
person.qualification();