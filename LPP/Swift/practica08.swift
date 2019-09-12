//Pedro Gimenez Aldeguer 15419933C

/*
================================
Ejercicio 1: obtenerFrencuencias
================================
*/

func obtenerFrecuencias(respuestas: [Int]) -> [Int] {

      var histograma = Array(repeating: 0, count: 10)
      for res in respuestas {
         histograma[res] += 1
      }
      return histograma
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
        i += 1
    }
}


// DEMOSTRACIÓN

print("Ejercicio 1")

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
   if (valores.count <= 1) {
      return []
   } else {
      let primero = valores.first!
      let segundo = Array(valores.dropFirst()).first!
      let resto = Array(valores.dropFirst())
      if f(primero) == segundo {
         return [(primero, segundo)] + compruebaParejas(resto, funcion: f)
      } else {
         return compruebaParejas(resto, funcion: f)
      }
   }
}

// DEMOSTRACIÓN

func cuadrado(x: Int) -> Int {
   return x * x
}

print("\nEjercicio 2")

print((compruebaParejas([2, 4, 16, 5, 10, 100, 105], funcion: cuadrado)))

/*
=========================
Ejercicio 3: ArbolBinario
=========================
*/

indirect enum ArbolBinario {
   case nodo(Int, ArbolBinario, ArbolBinario)
   case vacio
}

func suma(_ arbol: ArbolBinario) -> Int {
   switch arbol {
   case let .nodo(valor, hijoIzq, hijoDer):
      return valor + suma(hijoIzq) + suma(hijoDer)
   case .vacio:
      return 0
   }
}


print("\nEjercicio 3")

let arbol: ArbolBinario = .nodo(8, .nodo(2, .vacio, .vacio), .nodo(12, .vacio, .vacio))
print("La suma del árbol binario es: \(suma(arbol))")
// Imprime 22


/*
=======================
Ejercicio 4: coinciden
=======================
*/

func coinciden(parejas: [(Int,Int)], funcion f: (Int)->Int) -> [Bool] {
    if parejas.isEmpty {
        return []
    }
    else {
        let primero = parejas.first!
        let resto = Array(parejas.dropFirst())
        return [f(primero.0) == primero.1] + coinciden(parejas:resto, funcion:f)
    }
}



print("\nEjercicio 4")

let array = [(2,4), (4,14), (4,16), (5,25), (10,100)]
print("Resultado coinciden:  \(coinciden(parejas: array, funcion: cuadrado))")
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

func aplica(movimientos: [Movimiento]) -> Double {
    var resultado = 0.0

    for movimiento in movimientos {
        switch movimiento {
        case let .deposito(cantidad):
            resultado = resultado + cantidad
        case let .cargoRecibo(_, cantidad):
            resultado = resultado - cantidad
        case let .cajero(cantidad):
            resultado = resultado - cantidad
        }
    }
    return resultado
}

print("\nEjercicio 5")

let movimientos: [Movimiento] = [.deposito(830.0), .cargoRecibo("Gimnasio", 45.0), .deposito(400.0), .cajero(100.0)]
print(aplica(movimientos: movimientos))
