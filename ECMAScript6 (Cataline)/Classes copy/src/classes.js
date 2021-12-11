class Car {
    constructor(brand,price = 10){
        this.brand = brand
        this.price = price
    }
    run(){
        console.log('correr')
    }
}

const civic = new Car('Gol',20)
const hb20 = new Car('Amarok',50)
civic.run()

console.log(civic)
console.log(hb20)