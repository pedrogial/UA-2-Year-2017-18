// Solución práctica 12: Programación Orientada a Objetos en Swift (1)

import Foundation

/*
===========
Ejercicio 1
===========
*/

print("Ejercicio 1:")
// Propiedades del tipo y observadores
print("a)")

struct Valor {
    var valor: Int = 0 {
        willSet {
            Valor.z += newValue
        }        
        didSet {
            if valor > 10 {
                valor = 10
            }
        }
    }
    static var z = 0
}

var c1 = Valor()
var c2 = Valor()
c1.valor = 20
c2.valor = 8
print(c1.valor + c2.valor + Valor.z)
// Imprime 46

// b) Inicializadores
print("b)")

func prueba(x: Int) -> Int? {
    if x < 100 {
        return nil
    } else {
        return x
    }
}

class A {
    var a = prueba(x: 100)
    var b = 0, c = 0
    init() {}
    init(b: Int) {
        self.b = b
    }
}

let a = A(b: 0)
if let b = a.a {
    print("El valor de a.a es: \(b)")
}

// c)
print("c)")

// Ejemplo 1

class B {
    let b: String = "Clase padre"
    var calculada: String {
        return "Clase padre"
    }
    func diAlgo() -> String {
        return "Algo"
    }
    static var estatica = 0
    static func estatico() -> String {
        return "Variable estática: \(estatica)"
    }
}

class C: B {
    let c: Int = 0
    override var calculada: String {
        return "Clase hija"
    }
    override func diAlgo() -> String {
        return super.diAlgo() + " clase derivada"
    }
    
    /* No se puede sobreescribir un método estático
    override static func estatico() -> String {
        return super.estatico() + " y estoy en la clase derivada"
    }
    */
}

let c = C()
print(c.b)
print(c.calculada)
print(c.diAlgo())
C.estatica = 10
print(C.estatico())


// Ejemplo 2


class Base {
    var almacenada = 1
    var calculada: Int {
        get {
            return almacenada + 1
        }
        set {
            almacenada = newValue - 1
        }
    }
    static var propiedad = 0
    static func metodo() -> Int {
        return propiedad * 2
    }
    func paraSobrecargar() -> Int {
        return Base.propiedad + almacenada
    }       
}

class Derivada: Base {
    override var almacenada: Int {
        willSet {
            print("La almacenada va a cambiar")
        }
        didSet {
            print("La almacenada ha cambiado")
        }
    }
    override var calculada: Int  {
        willSet {
            print("La calculada va a cambiar")
        }
        didSet {
            print("La calculada ha cambiado")
        }
    }
    override func paraSobrecargar() -> Int {
        return super.paraSobrecargar() * 3
    }
}

class Rederivada: Derivada {
    override var almacenada: Int {
        get {
            return super.almacenada - 5
        }
        set {
            super.almacenada = (newValue + 5)
        }
    }
}

Derivada.propiedad = 5
let d = Derivada()
d.almacenada = -Derivada.metodo()
print(d.calculada)
print(d.paraSobrecargar())
d.calculada = 0
print(d.calculada)
print(d.almacenada)
let rederivada = Rederivada()
rederivada.almacenada = 8
print(rederivada.almacenada)


/*
===========
Ejercicio 2
===========
*/

print("\nEjercicio 2:\n")

func recorta(_ palabra: String, hasta: Int) -> String {
    if hasta >= palabra.count {
        return palabra
    } else {
       let start = palabra.startIndex
       let end =  palabra.index(start, offsetBy: hasta)
       return String(palabra[start..<end])
    }
}

let palabra = "Hola"
print(recorta(palabra, hasta: 2))
print(recorta(palabra, hasta: 3))
print(recorta(palabra, hasta: 4))
print(recorta(palabra, hasta: 5))

class MisPalabras {
    var guardadas: [String] = []
    func guarda(palabra: String) {
        guardadas = guardadas + [palabra]
    }
    var longitud: Int {
        get {
            return guardadas.reduce(0){$0 + $1.count}
        }
        set {
            if newValue > 0 && newValue < longitud {
                var nuevas: [String] = []
                var acum = 0
                var pos = 0
                while acum < newValue {
                    var palabra = guardadas[pos]
                    if palabra.count + acum > newValue {
                        let recortaHasta = newValue - acum
                        palabra = recorta(palabra, hasta: recortaHasta)
                    }
                    nuevas.append(palabra)
                    pos += 1
                    acum += palabra.count
                }
                guardadas = nuevas
            }
        }
        // Versión alternativa con FOS reduce
        // set {
        //     var hasta = newValue
        //     if hasta < longitud {
        //         guardadas = guardadas.reduce([]) {
        //             if hasta > 0 {
        //                 if hasta < $1.count {
        //                     let recortada = recorta($1, hasta: hasta)
        //                     hasta = 0
        //                     return $0 + [recortada]
        //                 }
        //                 hasta -= $1.count
        //                 return $0 + [$1]
        //             } else {
        //                 return $0
        //             }
        //         }
        //     }
        // }
    }
}

let palabras = MisPalabras()
palabras.guarda(palabra: "Hola")
palabras.guarda(palabra: "me")
palabras.guarda(palabra: "llamo")
palabras.guarda(palabra: "Yolanda")

print(palabras.longitud)
palabras.longitud = 10
print(palabras.guardadas)

/*
================================
Ejercicio 3: figuras geométricas
================================
*/

struct Punto {
    var x = 0.0, y = 0.0
}

struct Tamaño {
    var ancho = 0.0, alto = 0.0
}

struct AlmacenFiguras {
    static var rectangulos: [Rectangulo] = []
    static var circulos: [Circulo] = []
    static var numFiguras: Int {
        return rectangulos.count + circulos.count
    }
    static var areaTotal: Double {
        func areas() -> [Double] {
            return
                rectangulos.map() {$0.area} +
                circulos.map() {$0.area}
        }
        return areas().reduce(0.0, +)
    }
}

class Rectangulo {
    var origen: Punto
    var tamaño: Tamaño

    init(origen o: Punto, tamaño t: Tamaño) {
        origen = o
        tamaño = t
        AlmacenFiguras.rectangulos += [self]
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
        AlmacenFiguras.circulos += [self]
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



// DEMOSTRACIÓN


print("\nEjercicio 3\n")

let r = Rectangulo(origen:Punto(x:3, y:4), tamaño:Tamaño(ancho:10, alto:5))
print("Rectángulo con origen \(r.origen) y tamaño \(r.tamaño)")
print("centro: \(r.centro)   area: \(r.area)")
r.centro = Punto()
print("Con el nuevo centro \(r.centro) el nuevo origen es \(r.origen)")
print()

let circ = Circulo(centro:Punto(x:5, y:0), radio:10.0)
print("Círculo con centro \(circ.centro) y radio \(circ.radio)")
print("Area del círculo: \(circ.area)")
circ.area = 30.0
print("Con la nueva área \(circ.area) el nuevo radio es \(circ.radio)")
print()


print("Se han creado \(AlmacenFiguras.numFiguras) figuras y su area total es \(AlmacenFiguras.areaTotal)")


/*
==============================
Ejercicio 4: carrera de coches
==============================
*/


func rand(_ n: Int) -> Int {
    return random() % n
}

enum MarcaCoche: Int {
   case Mercedes=0, Ferrari, RedBull, McLaren

    static func random() -> MarcaCoche {
        let maxValue = McLaren.rawValue

        let r = rand(maxValue+1)
        return MarcaCoche(rawValue: r)!
    }

}


enum TipoCambio: Int {
    case automatico=0, manual

    static func random() -> TipoCambio {
        let maxValue = manual.rawValue

        let r = rand(maxValue+1)
        return TipoCambio(rawValue: r)!
    }
}

class Coche {
    var velocidadActual = 0.0
    var distanciaRecorrida = 0.0
    var marcha = 1
    static let velocidadMaxima = 150.0
    static let marchasMaxima = 6
    var marca : MarcaCoche

    init(marca: MarcaCoche) {
        self.marca = marca
    }
    var descripcion: String {
        return "\(marca)"
    }
    func seguimientoCarrera() {
        print("\(descripcion) viajando a \(velocidadActual) kilómetros por hora con la marcha \(marcha)")
        distanciaRecorrida += velocidadActual
    }
    func actualizaVelocidad() {}
}

class CocheAutomatico: Coche {
    override var velocidadActual: Double {
        didSet {
            marcha = min(Int(velocidadActual / 25.0) + 1, Coche.marchasMaxima)
            seguimientoCarrera()
        }
    }
    override var descripcion: String {
        return super.descripcion + " automatico"
    }
    override func actualizaVelocidad() {
      velocidadActual = Double(rand(Int(Coche.velocidadMaxima)) + 1)
    }
}

class CocheManual: Coche {
    override var marcha: Int {
        didSet {
            velocidadActual = 25.0 * Double(marcha)
            seguimientoCarrera()
        }
    }
    override var descripcion: String {
        return super.descripcion + " manual"
    }
    override func actualizaVelocidad() {
       marcha = rand(Coche.marchasMaxima) + 1
    }
}

class Carrera {
    var coches: [Coche] = []
    let numCoches: Int
    let tiempoFinal : Int
    var tiempoActual: Int = 0 {
        didSet {
            print("\nHoras transcurridas \(tiempoActual)")
        }
    }

    init(numCoches: Int, horas:Int) {
        self.numCoches = numCoches
        tiempoFinal = horas
        for _ in 0..<numCoches {
            switch TipoCambio.random() {
            case .automatico :
                coches.append(CocheAutomatico(marca: MarcaCoche.random()))
            case .manual :
                coches.append(CocheManual(marca: MarcaCoche.random()))
            }
        }
    }

    func empezar() {
        for t in 1...tiempoFinal {
            tiempoActual = t
            for coche in coches {
               coche.actualizaVelocidad()
            }
        }
    }

    func clasificacion() {
        let clasif = coches.sorted(by: {$0.distanciaRecorrida > $1.distanciaRecorrida})
        var i = 1
        for coche in clasif {
            print("\(i). \(coche.descripcion) (\(coche.distanciaRecorrida) kilómetros recorridos)")
            i+=1
        }
    }

    func descripcion() {
        print("\(numCoches) coches con una duración de \(tiempoFinal) horas")
        for coche in coches {
            print("    \(coche.descripcion)")
        }
    }

}


// DEMOSTRACIÓN

print("\nEjercicio 4\n")
srandom(UInt32(NSDate().timeIntervalSince1970))
let carrera = Carrera(numCoches: 2, horas: 3)
print("\nDescripción de la carrera:")
carrera.descripcion()
print("\n!!! Comienza la carrera !!!")
carrera.empezar()
print("\n!!! Clasificación !!!")
carrera.clasificacion()
