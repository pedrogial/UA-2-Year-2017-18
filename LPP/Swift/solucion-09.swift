
// Solución Práctica 9: Programación funcional en Swift: clausuras y funciones de orden superior

/*
-----------------------
Ejercicio 1: Cuestiones
-----------------------
*/

print("Ejercicio 1")
print("===========")
print("--- Apartado a")

let nums = [1,2,3,4,5,6,7,8,9,10]
print("""
  a.1) Solución: \(
    nums.filter{$0 % 3 == 0}.count
  )\n
  """)
// Devuelve la cantidad de números divisibles por 3: 3

let nums2 = [1,2,3,4,5,6,7,8,9,10]
print("""
  a.2) Solución: \(
    nums2.map{$0 + 100}.filter{$0 % 5 == 0}.reduce(0, +)
  )\n
  """)
// Devuelve la suma de todos los números incrementados en 100 múltiplos de 5: 215

let cadenas = ["En", "un", "lugar", "de", "La", "Mancha"]
print("""
  a.3) Solución: \(
    cadenas.sorted{$0.count < $1.count}.map{$0.count}
  )\n
  """)
// Devuelve la longitud de cada cadena del array ordenado de menor a mayor por
// la longitud de las cadenas: [2, 2, 2, 2, 5, 6]

let cadenas2 = ["En", "un", "lugar", "de", "La", "Mancha"]
print("""
  a.3) Solución: \(
    cadenas2.reduce([]) {
      (res: [(String, Int)], c: String) -> [(String, Int)] in
        res + [(c, c.count)]}.sorted(by: {$0.1 < $1.1})
  )\n
  """)
// Devuelve un array de tuplas con cada cadena y su longigud, ordenado
// de menor a mayor por la longitud (segundo elemento de la tupla):
// [("En", 2), ("un", 2), ("de", 2), ("La", 2), ("lugar", 5), ("Mancha", 6)]

print("--- Apartado b")

func f(nums: [Int], n: Int) -> Int {
    return nums.filter{$0 == n}.count
}

// Explicación de funcionamiento:
// Dado un array de enteros y un número, devuelve el 
// número de veces que se repite el número en el array

// Ejemplo:
print("""
  b.1) Solución: Cuenta cuantos hay igual a n en un array de enteros.
    f(nums: [1, 2, 3, 2, 4, 5, 2, 2], n: 2) = \(
    f(nums: [1, 2, 3, 2, 4, 5, 2, 2], n: 2) )\n
  """)


func g(nums: [Int]) -> [Int] {
    return nums.reduce([], {(res: [Int], n: Int) -> [Int] in
                        if !res.contains(n) {
                            return res + [n]
                        } else {
                            return res
                        }
                    })
}

// Explicación de funcionamiento:
// Elimina duplicados de un array

// Ejemplo:

print("""
  b.2) Solución: Elimina de un Array de enteros los valores repetidos.
    g(nums: [1, 2, 3, 2, 4, 3, 2, 2]) = \(
    g(nums: [1, 2, 3, 2, 4, 3, 2, 2]) )\n
  """)

func h(nums: [Int], n: Int) -> ([Int], [Int]) {
   return nums.reduce(([],[]), {(res: ([Int],[Int]), num: Int ) -> ([Int],[Int]) in
                            if (num >= n) {
                                return (res.0, res.1 + [num])
                            } else {
                                return ((res.0 + [num], res.1))
                            }
                        })
}

// Explicación de funcionamiento:
// Divide un array de enteros en dos partes: números menores que n y mayores o iguales que n

let numeros2 = [102, 23, 56, 231, 12, 452]
let pivote = 100
let dosArrays = h(nums: numeros2, n: pivote)

print("""
  b.3) Solución: Devuelve una pareja indicando cuantos elementos de un array de enteros
                 (nums) son menores y cuantos mayores o iguales que un valor dado (n).
    h(nums: [1, 2, 3, 4, 5], n: 3) = \(
    h(nums: [1, 2, 3, 4, 5], n: 3) )\n
  """)

print("Apartado c")

func suma(palabras: [String], contienen: Character) -> Int {
  return palabras.filter() {$0.contains(contienen)}.reduce(0) {$0 + $1.count}
}
print("""
  c.1)
    suma(palabras: \(cadenas), contienen: "a") = \(
    suma(palabras:   cadenas , contienen: "a") )\n
  """)

// c.2)
func sumaMenoresMayores(nums: [Int], pivote: Int) -> (Int, Int) {
  return nums.reduce((0,0)) {($1<pivote) ? ($0.0+$1, $0.1) : ($0.0, $0.1+$1)}
}
print("""
  c.2)
    sumaMenoresMayores(nums: \(nums), pivote: 8) = \(
    sumaMenoresMayores(nums:   nums , pivote: 8) )\n
  """)


/*
---------------------------
Ejercicio 2: Arbol Genérico
---------------------------
*/

indirect enum Arbol<T> {
   case nodo(T, [Arbol])
}


let arbolInt: Arbol = .nodo(53, [
                        .nodo(13, []),
                        .nodo(32, []),
                        .nodo(41, [
                          .nodo(36, []),
                          .nodo(39, [])
                          ])
                        ])

let arbolString: Arbol = .nodo("Zamora", [
                           .nodo("Buendía", [
                             .nodo("Albeza", []),
                             .nodo("Berenguer", []),
                             .nodo("Bolardo", [])
                             ]),
                           .nodo("Galván", [])
                           ])

/* Versión recursión mutua */

func toArray<T>(arbol: Arbol<T>) -> [T] {
    switch arbol {
        case let .nodo(dato, hijos):
            return [dato] + toArray(bosque: hijos)
    }
}

func toArray<T>(bosque: [Arbol<T>]) -> [T] {
    if let primero = bosque.first {
        let resto = Array(bosque.dropFirst())
        return toArray(arbol: primero) + toArray(bosque: resto)
    } else {
        return []
    }
}

print("Ejercicio 2")
print("===========")
print("-- Recursión mutua:")
print(toArray(arbol: arbolInt))
print(toArray(arbol: arbolString))

/* Versión FOS */

func toArrayFOS<T>(arbol: Arbol<T>) -> [T] {
    switch arbol {
        case let .nodo(dato, hijos):
            return hijos.map(toArrayFOS).reduce([dato], +)
    }
}

print("-- FOS:")
print(toArrayFOS(arbol: arbolInt))
print(toArrayFOS(arbol: arbolString))

/*
-----------------------------
Ejercicio 3: Listado de notas
-----------------------------
*/

import Foundation

func imprimirListadoAlumnos(_ alumnos: [(String, Double, Double, Double, Int)]) {
    print("Alumno   Parcial1   Parcial2   Cuest  Años")
    for alu in alumnos {
        alu.0.withCString {
            print(String(format:"%-10s %5.2f      %5.2f    %5.2f  %3d", $0, alu.1,alu.2,alu.3,alu.4))
        }
    }
}


func imprimirListadosNotas(_ alumnos: [(String, Double, Double, Double, Int)]) {
    var alumnosOrdenados: [(String, Double, Double, Double, Int)]

    print("LISTADO ORIGINAL")
    imprimirListadoAlumnos(alumnos)

    print("LISTADO ORDENADO por Nombre")
    alumnosOrdenados = alumnos.sorted(by: {a1, a2 in a1.0 < a2.0})
    imprimirListadoAlumnos(alumnosOrdenados)

    print("LISTADO ORDENADO por Parcial1")
    alumnosOrdenados = alumnos.sorted(by: {a1,a2 in a1.1 > a2.1})
    imprimirListadoAlumnos(alumnosOrdenados)

    print("LISTADO ORDENADO por Parcial2")
    alumnosOrdenados = alumnos.sorted(by: {$0.2 < $1.2})
    imprimirListadoAlumnos(alumnosOrdenados)

    print("LISTADO ORDENADO por Parcial 2 y Año de Matriculación")
    alumnosOrdenados = alumnos.sorted(by: {a1, a2 in
                                             if a1.2 > a2.2 {
                                                return true
                                             } else if a1.2 == a2.2 {
                                                return a1.4 > a2.4
                                             } else {
                                                return false
                                             }
                                          }
                                      )
    imprimirListadoAlumnos(alumnosOrdenados)

    print("LISTADO ORDENADO por Nota para aprobar en Junio")
    alumnosOrdenados = alumnos.sorted(by: {a1, a2 in
                                              let notaP3Alumno1 = (5 / 0.3) - a1.3 * (0.1 / 0.3) - a1.1 - a1.2
                                              let notaP3Alumno2 = (5 / 0.3) - a2.3 * (0.1 / 0.3) - a2.1 - a2.2
                                              return notaP3Alumno1 < notaP3Alumno2
                                          }
                                     )
    imprimirListadoAlumnos(alumnosOrdenados)
}

// DEMOSTRACIÓN

print("Ejercicio 3")
print("===========")
let listaAlumnos = [("Pepe", 8.45, 3.75, 6.05, 1), 
                    ("Maria", 9.1, 7.5, 8.18, 1), 
                    ("Jose", 8.0, 6.65, 7.96, 1),
                    ("Carmen", 6.25, 1.2, 5.41, 2), 
                    ("Felipe", 5.65, 0.25, 3.16, 3), 
                    ("Carla", 6.25, 1.25, 4.23, 2), 
                    ("Luis", 6.75, 0.25, 4.63, 2), 
                    ("Loli", 3.0, 1.25, 2.19, 3)]
imprimirListadosNotas(listaAlumnos)

/*
------------------------------------
Ejercicio 4: Expresiones de clausura
------------------------------------
*/


print("\nEjercicio 4")
print("===========\n")


// A) Número de alumnos que han aprobado primer parcial y suspendido el segundo
print(listaAlumnos.filter { $0.1 >= 5 && $0.2 < 5}.count)

// B) Nota que deben tener en el parcial 3 para sacar un 5 en la nota final
print(listaAlumnos.map {(alumno: (String, Double, Double, Double, Int)) -> Double in 
                          let nota = (5 / 0.3) - alumno.3 * (0.1 / 0.3) - alumno.1 - alumno.2
                          return nota})

// C) Nota media de todos los alumnos: tupla (media_p1, media_p2, media_cuest)
var tupla = listaAlumnos.reduce((0,0,0), {(result, alumno) in 
                                         return (result.0 + alumno.1, result.1 + alumno.2, result.2 + alumno.3)
})
tupla = (tupla.0 / Double(listaAlumnos.count), tupla.1 / Double(listaAlumnos.count), tupla.2 / Double(listaAlumnos.count))
print(tupla)

/*
=================================
Ejercicio 5: calcular(exp:sobre:)
=================================
*/


enum Operando {
   case primero
   case segundo
   case valor(Double)
}

enum Operacion {
   case suma
   case resta
   case mult
   case div
}

func parse(operando: String) -> Operando? {
   switch operando {
      case "$0":
         return Operando.primero
      case "$1":
         return Operando.segundo
      default:
         if let num = Double(operando) {
            return Operando.valor(num)
         } else {
            return nil
         }
   }
}

func parse(operacion: String) -> Operacion? {
   switch operacion {
      case "+":
         return Operacion.suma
      case "-":
         return Operacion.resta
      case "*":
         return Operacion.mult
      case "/":
         return Operacion.div
      default:
         return nil
   }
}

func parse(exp: String) -> (op1: Operando, op2: Operando, op: Operacion)? {
   let arrayPalabras = exp.split(separator: " ").map(String.init)
   if let op1 = parse(operando: arrayPalabras[0]),
      let op2 = parse(operando: arrayPalabras[2]),
      let op = parse(operacion: arrayPalabras[1]) {
         return (op1, op2, op)
      }
   else {
      return nil
   }
}

func getValor(tupla: (Double, Double), operacion: Operando) -> Double {
   switch operacion {
      case .primero:
         return tupla.0
      case .segundo:
         return tupla.1
      case let .valor(valor):
         return valor
   }
}

func getFunc(op: Operacion) -> (Double, Double) -> Double {
   switch op {
   case .suma:
      return {$0 + $1}
   case .mult:
      return {$0 * $1}
   case .resta:
      return {$0 - $1}
   case .div:
      return {$0 / $1}
   }
}

func construyeFunc(op1: Operando, op2: Operando, op: Operacion) -> ((Double, Double)) -> Double {
   return {(tupla: (Double, Double)) -> Double in
               let valor1 = getValor(tupla: tupla, operacion: op1)
               let valor2 = getValor(tupla: tupla, operacion: op2)
               let f = getFunc(op: op)
               return f(valor1, valor2)
   }
}

func calcular(exp str: String, sobre tuplas: Array<(Double, Double)>) -> [Double]? {
   if let exp = parse(exp: str) {
      let f = construyeFunc(op1: exp.op1, op2: exp.op2, op: exp.op)
      return tuplas.map(f)
   } else {
      return nil
   }
}


// DEMOSTRACIÓN

print("\nEjercicio 5")
print("===========\n")

let tuplas = [(1.0, 2.5), (10.8, 3.3), (-1.0, 12.0), (-3.4, 4.0)]

print(calcular(exp: "$1 * 2.0", sobre: tuplas)!)
print(calcular(exp: "$0 - 5.0", sobre: tuplas)!)
print(calcular(exp: "$0 + $1", sobre: tuplas)!)
