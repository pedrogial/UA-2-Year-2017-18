//
//Ejercicio 1
//

/*
a) El siguiente código usa observadores de propiedades y una variable del tipo (estática).

¿Qué se imprime al final de su ejecución? Reflexiona sobre el funcionamiento del código, compruébalo con el compilador y experimenta haciendo cambios y comprobando el resultado.
*/

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


/*
b) El siguiente código utiliza la inicialización de una clase.

¿Qué errores tiene? ¿Qué se imprimiría en su ejecución una vez arreglado? Intenta descubrirlo sin utilizar el compilador. Prueba distintas formas de arreglar el código cambiando lo mínimo posible de lo ya definido (por ejemplo, no debes cambiar la función prueba). Compruébalo con el compilador.

*/

func prueba(x: Int) -> Int? {
    if x < 100 {
        return nil
    } else {
        return x
    }
}

class A {
    var a = prueba(x: 100)
    var b = 0;
    var c = 0;
    init() {}
    init(b: Int) {
        self.b = c
    }
}

let a = A(b: 0)
let b: Int = a.a!
print("El valor de a.a es: \(b)")

/*
c) Escribe un ejemplo de código en el que definas una relación de herencia entre una clase base y una clase derivada. Comprueba en el código que un objeto de la clase derivada hereda las propiedades y métodos de la clase base.

Investiga sobre lo el funcionamiento de la herencia en Swift. Escribe ejemplos en donde compruebes este funcionamiento. Algunos ejemplos de preguntas que puedes investigar (puedes añadir tú más preguntas):

    ¿Se puede sobreescribir el valor de una propiedad almacenada? ¿Y calculada?Sí
  
    ¿Se puede añadir un observador a una propiedad de la clase base en una clase derivada?Sí

    ¿Hereda la clase derivada propiedades y métodos estáticos de la clase base?Sí

    ¿Cómo se puede llamar a la implementación de un método de la clase base en una sobreescritura de ese mismo método en la clase derivada? No*/


//
//Ejercicio2
//

class MisPalabras {
    var guardadas: [String] = []
    func guarda(palabra: String) {
        guardadas = guardadas + [palabra]
    }
}

let palabras = MisPalabras()
palabras.guarda(palabra: "Hola")
palabras.guarda(palabra: "me")
palabras.guarda(palabra: "llamo")
palabras.guarda(palabra: "Yolanda")
print(palabras.guardadas)
// ["Hola", "me", "llamo", "Yolanda"]