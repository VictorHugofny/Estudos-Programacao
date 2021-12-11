const fruits = ['laranja','morango',',maçã']

const [a, b] = fruits

console.log(a,b)

const person = {
    firtsName: 'Victor',
    secondName: 'Hugo',
    age: 23,
    address: {
        city: 'Bahia',
        regio: 'BA',
    }
}

const {firtsName, secondName, address:{city}} = person
console.log(firtsName, secondName, city)

const showFullName = ({firtsName, secondName}) =>{
    console.log(`${firtsName} ${secondName}`)
}

showFullName(person)