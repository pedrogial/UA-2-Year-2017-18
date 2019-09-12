
// Solución Práctica 8: Introducción y programación funcional en Swift

/*
================================
Ejercicio 1: obtenerFrencuencias
================================
*/

func obtenerFrecuencias(respuestas: [Int]) -> [Int] {
    var frecuencias = Array(repeating: 0, count: 10)
    for puntuacion in respuestas {
        frecuencias[puntuacion] += 1
    }
    return frecuencias
}

func mayorFrecuencia(frecuencias: [Int]) -> Int {
    var mayor = frecuencias[0]
    for frec in frecuencias[1..<frecuencias.count] {
        if frec > mayor {
            mayor = frec
        }
    }
    return mayor
}

func imprimir(frecuencias: [Int], maxAsteriscos: Int) {
    let mayor = mayorFrecuencia(frecuencias:frecuencias)
    var i = 0
    for frec in frecuencias {
        let numEscalado = frec * maxAsteriscos / mayor
        print("\(i): " + String(repeating: "*", count: numEscalado))
        i = i + 1
    }
}


// DEMOSTRACIÓN

print("Ejercicio 1")
print("===========\n")
let respuestas = [0,0,1,1,2,1,2,3,5,1,2,2,2,6]
print("Valores: \(respuestas)" )
let frec = obtenerFrecuencias(respuestas: respuestas)
print("Frecuencias: \(frec)")
print("\nHistograma")
print("----------")
imprimir(frecuencias: frec, maxAsteriscos: 10)

/*
================================
Ejercicio 2: compruebaParejas
================================
*/

func compruebaParejas(_ valores: [Int], funcion f: (Int) -> Int) -> [(Int,Int)] {
    if let primero = valores.first, let segundo = valores.dropFirst().first {
        let resto = Array(valores.dropFirst())
        if f(primero) == segundo {
            return [(primero, segundo)] + compruebaParejas(resto, funcion: f)
        } else {
            return compruebaParejas(resto, funcion: f)
        }
    } else {
        return []
    }
}

// DEMOSTRACIÓN

func cuadrado(x: Int) -> Int {
   return x * x
}
let array2a = [2, 4, 16, 5, 10, 100, 105]
print("\nEjercicio 2")
print("============\n")
print("compruebaParejas(\(array2a), cuadrado): \(compruebaParejas(array2a, funcion: cuadrado))")

/*
=========================
Ejercicio 3: ArbolBinario
=========================
*/

indirect enum ArbolBinario {
   case nodo(Int, ArbolBinario, ArbolBinario)
   case vacio
}

func suma(arbolb: ArbolBinario) -> Int {
   switch arbolb {
   case let .nodo(dato, hijoIzq, hijoDer):
      return dato + suma(arbolb: hijoIzq) + suma(arbolb: hijoDer)
   case .vacio:
      return 0
   }
}

// DEMOSTRACIÓN
print("\nEjercicio 3")
print("============\n")
let arbol: ArbolBinario = .nodo(8, .nodo(2, .vacio, .vacio), .nodo(12, .vacio, .vacio))
print("La suma del árbol binario es: \(suma(arbolb: arbol))")
// Imprime 22


/*
=======================
Ejercicio 4: coinciden
=======================
*/

func coinciden(parejas: [(Int,Int)], funcion f: (Int)->Int) -> [Bool] {
    if let (x, y) = parejas.first {
        let resto = Array(parejas.dropFirst())
        return [f(x) == y] + coinciden(parejas: resto, funcion: f)
    }
    else {
        return []
    }
}

// DEMOSTRACIÓN

print("\nEjercicio 4)")
print("============\n")
let array4: [(Int,Int)] = [(2,4), (4,14), (4,16), (5,25), (10,100)]
print("coinciden(\(array4), cuadrado):  \(coinciden(parejas: array4, funcion: cuadrado))\n")
// Imprime: Resultado coinciden:  [true, false, true, true, true]

/*
================================
Ejercicio 5: aplica(movimientos:)
================================
*/


enum Movimiento {
    case deposito(Double)
    case cargoRecibo(String, Double)
    case cajero(Double)
}

func aplica(movimientos: [Movimiento]) -> (Double, [String]) {
    var resultado = 0.0
    var conceptos = [String]()
    for movimiento in movimientos {
        switch movimiento {
        case let .deposito(cantidad):
            resultado = resultado + cantidad
        case let .cargoRecibo(concepto, cantidad):
            resultado = resultado - cantidad
            conceptos.append(concepto)
        case let .cajero(cantidad):
            resultado = resultado - cantidad
        }
    }
    return (resultado, conceptos)
}

// DEMOSTRACIÓN

print("\nEjercicio 5")
print("============\n")
let movimientos: [Movimiento] = [.deposito(830.0), .cargoRecibo("Gimnasio", 45.0), .deposito(400.0), .cajero(100.0), .cargoRecibo("Fnac", 38.70)]
print("aplica(\(movimientos)): \(aplica(movimientos: movimientos))")
// Imprime (1046.3, ["Gimnasio", "Fnac"])


/*
=========================
Ejercicio 6: ArbolGenérico
=========================
*/

indirect enum Arbol {
   case nodo(Int, [Arbol])
}


/*
Definimos el árbol

    10
   / | \
  3  5  8
  |
  1

*/

func suma(arbol: Arbol, cumplen condicion: (Int) -> Bool ) -> Int {
    switch arbol {
        case let .nodo(dato, hijos): 
            if (condicion(dato)) {
                return dato + suma(bosque: hijos, cumplen: condicion)
            }
           return suma(bosque: hijos, cumplen: condicion)
    }
}

func suma(bosque: [Arbol], cumplen condicion: (Int) -> Bool) -> Int {
    if let primero = bosque.first {
        let resto = Array(bosque.dropFirst())
        return suma(arbol: primero, cumplen: condicion) + suma(bosque: resto, cumplen: condicion)
    } else {
        return 0
    }
}


// DEMOSTRACIÓN
print("\nEjercicio 6")
print("============\n")
let arbol1 = Arbol.nodo(10, [])
let arbol3 = Arbol.nodo(3, [arbol1])
let arbol5 = Arbol.nodo(5, [])
let arbol8 = Arbol.nodo(8, [])
let arbol10 = Arbol.nodo(10, [arbol3, arbol5, arbol8])

func esPar(x: Int) -> Bool {
    return x % 2 == 0
}

print("La suma del árbol genérico es: \(suma(arbol: arbol10, cumplen: esPar))")
// Imprime 28
