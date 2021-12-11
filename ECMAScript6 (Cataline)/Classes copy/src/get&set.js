class Person {
    constructor(name){
        this._name = name
    }
    get name(){
        return this._name
    }
    set name(newName){
        this._name = newName
    }
}

const person = new Person('Victor Hugo')

console.log(person.name)