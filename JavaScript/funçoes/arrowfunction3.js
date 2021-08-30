let comparacomThis = function(param){
    console.log(this ===param)
}
comparacomThis(global)

const obj={}
comparacomThis = comparacomThis.bind(obj)
comparacomThis(global)
comparacomThis(obj)

let comparacomThisArrow = param => console.log(this===param)
comparacomThisArrow(global)
comparacomThisArrow(this)
comparacomThisArrow(module.exports)
comparacomThisArrow(obj)

comparacomThisArrow = comparacomThisArrow.bind(obj) //não vai variar por conta do ser arrow
comparacomThisArrow(obj)
comparacomThisArrow(module.exports)