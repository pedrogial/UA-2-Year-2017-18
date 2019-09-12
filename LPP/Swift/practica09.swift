/*
Ejercicio 1

a) Indica qué devuelven las siguientes expresiones:

a.1)
*/

//let nums = [1,2,3,4,5,6,7,8,9,10]
//print(nums.filter{$0 % 3 == 0}.count)

/*
//a.2)

let nums2 = [1,2,3,4,5,6,7,8,9,10]
print(nums2.map{$0+100}.filter{$0 % 5 == 0}.reduce(0,+))


//a.3)

let cadenas = ["En", "un", "lugar", "de", "La", "Mancha"]
print(cadenas.sorted{$0.count < $1.count}.map{$0.count})

//a.4)

let cadenas2 = ["En", "un", "lugar", "de", "La", "Mancha"]
print(cadenas2.reduce([]) {(res: [(String, Int)], c: String) ->
                        [(String, Int)] in res + [(c, c.count)]}.sorted(by: {$0.1 < $1.1}))


//b) Explica qué hacen las siguientes funciones y pon un ejemplo de su funcionamiento:

//b.1)

func f(nums3: [Int], n: Int) -> Int {
    return nums3.filter{$0 == n}.count
}
var nums3 : [Int] = [1, 2, 3, 4, 5]
var n : Int = 2

print(f(nums3 : nums3, n : n))


//b.2)

func g(hola: [Int]) -> [Int] {
    return hola.reduce([], {(res: [Int], n: Int) -> [Int] in
                        if !res.contains(n) {
                            return res + [n]
                        } else {
                            return res
                        }
                    })
}

var hola2 : [Int] = [1, 2, 3, 4, 5]
print(g(hola : hola2))
*/
//b.3)

func h(nums: [Int], n: Int) -> ([Int], [Int]) {
   return nums.reduce(([],[]), {(res: ([Int],[Int]), num: Int ) -> ([Int],[Int]) in
                            if (num >= n) {
                                return (res.0, res.1 + [num])
                            } else {
                                return ((res.0 + [num], res.1))
                            }
                        })
}
var nuevo : [Int] = [1, 2, 3, 4, 5]
var n : Int = 2
print(h(nums:nuevo, n : n))



//c) Implementa las siguientes funciones con funciones de orden superior.

//c.1) Función suma(palabras:contienen:):

func suma(palabras: [String], contienen: Character) -> Int{
        return palabras.reduce(0, {(res: Int, d: String) -> Int in
                        if d.contains(contienen) {
                            return res + d.count
                        } else {
                            return res
                        }
                    })
}
var nuevos : [String] = ["d", "ab", "an", "a", "a"]
var ns : Character = "a"
print(suma(palabras:nuevos, contienen : ns))

//que recibe una array de cadenas y devuelve la suma de las longitudes de las cadenas que contiene el carácter que se //pasa como parámetro.

//c.2) Función sumaMenoresMayores(nums:pivote:):


func sumaMenoresMayores(nums: [Int], pivote: Int) -> (Int, Int){
    return nums.reduce((0 , 0), {(res: (Int , Int), d: Int) -> (Int, Int)in
                        if pivote <= d {
                            return ( res.0 ,res.1 + d)
                        } else {
                            return (res.0 + d, res.1)
                        }
                    })

}

var nuevoss : [Int] = [1, 2, 3, 4, 5]
var nss : Int = 2
print(sumaMenoresMayores(nums:nuevoss, pivote : nss))

//que recibe un array de números y un número pivote y devuelve una tupla con la suma de los números menores y mayores o iguales que el pivote.


//Ejercicio 2

indirect enum Arbol<T> {
     case vacia
     case nodo(T, Lista<T>)
}

func 

