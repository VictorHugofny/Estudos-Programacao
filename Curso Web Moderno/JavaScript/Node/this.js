console.log(this === global)
console.log(this === module)
console.log(this === module.exports)
console.log(this === exports)
//aponta no escopo de exports.

function This(){
    //aponto no escopo global
    console.log(this === exports)
    console.log(this === global)
}