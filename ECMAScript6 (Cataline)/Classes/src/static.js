class Calculator{
    static sum(a,b){
    return a + b
    }
}


console.log(Calculator.sum(10,5))

class Person{
    constructor(firstName, SecondName){
        this.firstName = firstName
        this.SecondName = SecondName
    }
    get fullname(){
        return Person.joinNames(this.firstName,this.SecondName)
    }
    static joinNames(firstName, SecondName){
        return firstName + ' ' + SecondName
    }
}

const person = new Person('Victor','Hugo')

console.log(person.fullname)