
/*
===========
Ejercicio 1
===========
*/

print("\nEjercicio 1:")

// a)
print("\na)")

protocol A {
    var a: Int {get set}
    func foo(a: Int, b: Int) -> Int?
}

protocol B {
    mutating func bar()
}

struct MiStruct: A, B {
    var a = 10
    func foo(a: Int, b: Int) -> Int? {
        let res = a > 10 ? a : b
        return res
    }
    mutating func bar() {
        a += 1
    }
}

print(MiStruct())


// b)
print("\nb)")

protocol GeneradorNumerosAleatorios {
    func random() -> Double
}

class GeneradorLinealCongruente: GeneradorNumerosAleatorios {
    var ultimoRandom = 42.0
    let m = 139968.0
    let a = 3877.0
    let c = 29573.0
    func random() -> Double {
        let number = ultimoRandom * a + c
        ultimoRandom = number.truncatingRemainder(dividingBy: m)
        return ultimoRandom / m
    }
}

class GeneradorFake: GeneradorNumerosAleatorios {
    func random() -> Double {
        return 0.1
    }
}

class Dado {
    let caras: Int
    let generador: GeneradorNumerosAleatorios
    init(caras: Int, generador: GeneradorNumerosAleatorios) {
        self.caras = caras
        self.generador = generador
    }
    func tirar() -> Int {
        return Int(generador.random() * Double(caras)) + 1
    }
}

var dadoOK = Dado(caras: 6, generador: GeneradorLinealCongruente())
var dadoFake = Dado(caras: 6, generador: GeneradorFake())
for _ in 1...5 {
    print("La tirada del dado bueno es \(dadoOK.tirar())")
}
for _ in 1...5 {
    print("La tirada del dado falso es \(dadoFake.tirar())")
}


// 1c)
print("\nc)")


struct Equipo: Comparable {
    let puntos: Int
    let nombre: String

    static func == (primero: Equipo, segundo: Equipo) -> Bool {
        return 
            primero.puntos == segundo.puntos &&
            primero.nombre == segundo.nombre
    }

    static func < (primero: Equipo, segundo: Equipo) -> Bool {
        return
            primero.puntos < segundo.puntos ||
            (primero.puntos == segundo.puntos && primero.nombre < segundo.nombre)
    }
}

let ejemplo = [
    Equipo(puntos: 5, nombre: "Hercules"),
    Equipo(puntos: 10, nombre: "Valencia"),
    Equipo(puntos: 8, nombre: "Betis"),
    Equipo(puntos: 1, nombre: "Elche"),
    Equipo(puntos: 5, nombre: "Leganés"),
    Equipo(puntos: 10, nombre: "Barça")
    ]

for e in ejemplo.sorted() {
    print(e)
}

/*
===========
Ejercicio 2
===========
*/

print("\nEjercicio 2:")


// a)
print("\na)")

protocol X {
   var x: Int { get }
}
class Xb: X {
   var x = 0
   var b = 0
}
class Xc: X {
   var x = 1
   var c = 0
}

var array: [X] = [Xb(), Xc()]
for i in array {
   if i is Xb {
       print("x: \(i.x), b: \((i as! Xb).b)")
   } else {
       print("x: \(i.x), c: \((i as! Xc).c)")
    
   }
}

// debe imprimir:
// x: 0, b: 0
// x: 1, c: 0

// b)
print("\nb)")

protocol TieneVelocidad {
    func velocidadActual () -> Double
}

class Vehiculo {
    var velocidad = 0.0
    func velocidadActual() -> Double {
        return velocidad
    }
}

class Tren {
    static let velocidadEnMarcha = 300.0
    var pasajeros = 0
    var enMarcha = false
}

extension Vehiculo: TieneVelocidad {}
extension Tren: TieneVelocidad {
    func velocidadActual() -> Double {
        return enMarcha ? Tren.velocidadEnMarcha : 0.0
    }
}

var vehiculo1 = Vehiculo()
var tren1 = Tren()
tren1.enMarcha = true

let transportes: [TieneVelocidad] = [vehiculo1, tren1]

for i in transportes {
    print(i.velocidadActual())
}


// 2c)
print("\nc)")

indirect enum Arbol<T> {
   case nodo(T, [Arbol])
}

extension Arbol where T: Comparable {
    func min() -> T {
        switch self {
            case let .nodo(dato, hijos):
                return hijos.map{$0.min()}.reduce(dato){$0 < $1 ? $0 : $1}
        }
    }
}

let arbolEquipos: Arbol =
    .nodo(Equipo(puntos: 5, nombre: "Hercules"), [
        .nodo(Equipo(puntos: 10, nombre: "Valencia"), []),
        .nodo(Equipo(puntos: 8, nombre: "Betis"), []),
        .nodo(Equipo(puntos: 1, nombre: "Elche"), [
            .nodo(Equipo(puntos: 5, nombre: "Leganés"), []),
            .nodo(Equipo(puntos: 10, nombre: "Barça"), [])
            ])
        ])

print(arbolEquipos.min())


/*
===========
Ejercicio 3
===========
*/

print("\nEjercicio 3:")

import Foundation

struct Punto {
    var x = 0.0, y = 0.0
}

struct Tamaño {
    var ancho = 0.0, alto = 0.0
}

struct AlmacenFiguras {
    static var figuras: [Figura] = []
    static var numFiguras: Int {
        return figuras.count
    }
    static var areaTotal: Double {
        func areas() -> [Double] {
            return
                figuras.map() {$0.area}
        }
        return areas().reduce(0.0, +)
    }
    static func cuentaTipos() -> (Int, Int) {
        var nRect = 0, nCirc = 0
        for fig in figuras {
            print("- Descripción de la figura: \(fig.descripcion)")
            switch fig {
                case let rect as Rectangulo:
                    nRect += 1
                    print("Rectangulo con origen \(rect.origen) y tamaño \(rect.tamaño)")
                case let circ as Circulo:
                    nCirc += 1
                    print("Círculo con centro \(circ.centro) y radio \(circ.radio)")
                default:
                    print("Tipo de figura desconocida")
            }
        }
        return (nRect, nCirc)
    }
}

class Rectangulo {
    var origen: Punto
    var tamaño: Tamaño

    init(origen o: Punto, tamaño t: Tamaño) {
        origen = o
        tamaño = t
        AlmacenFiguras.figuras += [self]
    }

    var centro: Punto {
        get {
            let centroX = origen.x + (tamaño.ancho / 2)
            let centroY = origen.y + (tamaño.alto / 2)
            return Punto(x: centroX, y: centroY)
        }
        set {
            origen.x = newValue.x - (tamaño.ancho / 2)
            origen.y = newValue.y - (tamaño.alto / 2)
        }
    }

    var area: Double {
        return tamaño.ancho * tamaño.alto
    }
}


class Circulo {
    var centro: Punto
    var radio: Double

    init(centro c: Punto, radio r: Double) {
        centro = c
        radio = r
        AlmacenFiguras.figuras += [self]
    }

    var area: Double {
        get {
            return Double.pi * radio * radio
        }
        set {
            radio = sqrt(newValue / Double.pi)
        }
    }
}

protocol Figura {
    var centro: Punto {get set}
    var area: Double {get}
    var tamaño: Tamaño {get}
}


extension Rectangulo: Figura {}
extension Circulo: Figura {
    var tamaño: Tamaño {
        let diametro = radio * 2
        return Tamaño(ancho: diametro, alto: diametro)
    }
}

extension Figura {
    var descripcion: String {
        return "Una figura con centro: \(centro) y área: \(area)"
    }
}

let r = Rectangulo(origen:Punto(x:3, y:4), tamaño:Tamaño(ancho:10, alto:5))
let c = Circulo(centro:Punto(x:5, y:0), radio:10.0)

let tipos = AlmacenFiguras.cuentaTipos()
print("Total figuras: \(tipos)")

//
// Extensiones para el cumplimiento de Equatable
//

extension Tamaño: Equatable {
    static func == (izq: Tamaño, der: Tamaño) -> Bool {
        return
            izq.alto == der.alto &&
            izq.ancho == der.ancho
    }
}

extension Punto: Equatable {
    static func == (izq: Punto, der: Punto) -> Bool {
        return
            izq.x == der.x &&
            izq.y == der.y
    }
}

extension Rectangulo: Equatable {
    static func == (izq: Rectangulo, der: Rectangulo) -> Bool {
        return 
            izq.origen == der.origen &&
            izq.tamaño == der.tamaño
    }
}

extension Circulo: Equatable {
    static func == (izq: Circulo, der: Circulo) -> Bool {
        return
            izq.centro == der.centro &&
            izq.radio == der.radio
    }
}

let r2 = Rectangulo(origen:Punto(x:3, y:4), tamaño:Tamaño(ancho:10, alto:5))
let r3 = Rectangulo(origen:Punto(x:5, y:5), tamaño:Tamaño(ancho:10, alto:5))
let c2 = Circulo(centro:Punto(x:5, y:0), radio:10.0)
let c3 = Circulo(centro:Punto(x:5, y:0), radio:12.0)

print("r == r2: \(r == r2)")
print("r != r3: \(r != r3)")
print("c == c1: \(c == c2)")
print("c != c3: \(c != c3)")
