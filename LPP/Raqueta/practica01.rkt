;; Pedro Giménez Aldeguer

#lang r6rs
(import (rnrs)
        (schemeunit))

;;
;; Ejercicio 1: binario-a-decimal//binario-a-exadecimal ()
;;

;; Función principal a) binario-a-decimal

(define (binario-a-decimal b3 b2 b1 b0)
  (+ (* b3 (expt 2 3))
     (* b2 (expt 2 2))
     (* b1 (expt 2 1))
     (* b0 (expt 2 0))))

(display (binario-a-decimal 1 1 1 1))
(display "//")
(display (binario-a-decimal 1 1 0 1))
(display "\n")
(check-equal? (binario-a-decimal 1 1 1 1)  15)
(check-equal? (binario-a-decimal 1 1 0 1)  13)


;; Función principal b) binario-a-hexadecimal

(define (binario-a-hexadecimal b3 b2 b1 b0)
  (if (< (binario-a-decimal b3 b2 b1 b0) 10)
      (integer->char (+ (binario-a-decimal b3 b2 b1 b0) 48))
      (integer->char (+ (binario-a-decimal b3 b2 b1 b0) 55))))


(display (binario-a-hexadecimal 1 1 1 1))
(display "//")
(display (binario-a-hexadecimal 1 1 0 1))
(display "\n")
(check-equal? (binario-a-hexadecimal 1 1 1 1)  #\F)
(check-equal? (binario-a-hexadecimal 0 1 1 0)  #\6)




;;
;; Ejercicio 2: mayor-de-tres-v1//mayor-de-tres-v2 #
;;

;; Función principal mayor-que-tres-v1
(define (mayor-de-tres-v1 x y z)
   (if (and (> x y) (> x z)) x
            (if (and (> y y) (> y z)) y
                (if (and (> z y) (> z x)) z
                    (if (or (= z y) (= z x)) z
                        (if (or (= x y) (= x z)) x  y))))))

(display (mayor-de-tres-v1 3 7 16))
(display "//")
(display (mayor-de-tres-v1 3 4 2))
(display "\n")

;; Función auxiliar mayor

(define (mayor x y)
  (if (> x y)
      x
      y))

;; Función principal mayor-que-tres-v2

(define (mayor-de-tres-v2 x y z)
  (mayor (mayor x y) z))

(display (mayor-de-tres-v2 3 7 16))
(display "//")
(display (mayor-de-tres-v2 3 4 2))
(display "\n")
(check-equal? (mayor-de-tres-v2 3 7 16)  16)
(check-equal? (mayor-de-tres-v2 3 4 2)  4)




;;
;; Ejercicio 3: Modelo de sustitución aplicativo y normal #
;;

;; Función auxiliar f
(define (f x y)
    (+ (* 2 x) y))

;; Función auxiliar cuadrado

(define (cuadrado x)
    (* x x))

;;Expresión
;(f (cuadrado (+ 2 1)) (+ 1 1))

;;Orden aplicativo:
;(f (cuadrado (+ 2 1)) (+ 1 1))  -> Regla 4 "cuadrado"
;(f (* (+ 2 1) (+ 2 1)) (+ 1 1)) -> Regla 2 y 3 (+ 2 1) (+ 2 1)
;(f (* 3 3) (+ 1 1))             -> Regla 2 y 3 (+ 1 1)
;(f (* 3 3) 2)                   -> Regla 2 y 3 (* 3 3)
;(f 9 2)                         -> Regla 4 "f"
;(+ (* 2 9) 2)                   -> Regla 2 y 3 (* 2 9)
;(+ 18 2)                        -> Regla 2 y 3 (+ 18 2)  
;(20)

;;Orden normal:
;(f (cuadrado (+ 2 1)) (+ 1 1))       -> Regla 4 "f"
;(+ (* 2 (cuadrado (+ 2 1))) (+ 1 1)) -> Regla 4 "cuadrado"
;(+(* 2 (* (+ 2 1) (+ 2 1))) (+ 1 1)) -> Reg (integer->char (+ (binarila 3 (+ 2 1) (+ 2 1)
;(+(* 2 (* 3 3)) (+ 1 1))             -> Regla 3 (+ 1 1)
;(+(* 2 (* 3 3)) 2)                   -> Regla 3 (* 3 3)
;(+(* 2 9) 2)                         -> Regla 3 (* 2 9)
;(+ 18 2)                             -> Regla 3 (+ 18 2)
;(20)




;;
;; Ejercicio 4: tirada-ganadora #
;;

;;Función auxiliar
(define (hola x)
 (cond ((>= x 0) x
       ((< x 0) (- x)))))

;;Función auxiliar
(define (suma t)
  (+(car t)(cdr t)))

;; Función principal tirada-ganadora
(define (tirada-ganadora t1 t2)
  (cond (> (abs(- 7 (suma t1))) (abs(- 7(suma t2))) 2)
        (< (abs(- 7 (suma t2))) (abs(- 7(suma t1))) 1)
        (else 0)))

(display (tirada-ganadora (cons 1 3) (cons 1 6)))
(display "//")
(display (tirada-ganadora (cons 1 5) (cons 2 2)))
(display "//")
(display (tirada-ganadora (cons 6 2) (cons 3 3)))
(display "\n")




;;
;; Ejercicio 5: Guerra de barcos #
;;

;;Funcion auxial km/h-m/s

(define (km/h-m/s x)
  (/ (* x 1000) 3600))

;;Funcion auxial tiempo

(define (tiempo v)
  (/ 5000 (expt (km/h-m/s v) 2)))

;;Funcion auxial espacio

(define (espacio v)
  (* (km/h-m/s v) (tiempo v)))

;;Funcion auxiliar distancia-p

(define(distancia-p x1 x2 y1 y2)
  (sqrt( + (expt(- x2 x1) 2) (expt(- y2 y1) 2))))

;;Funcion principal dentro-alcance?

(define (dentro-alcance? x1 y1 x2 y2 v)
  (cond((<= (distancia-p x1 x2 y1 y2) (espacio v)) #\t)
  (else #\f)))

(display (dentro-alcance? 0 0 500 500 30))
(display "//")
(display (dentro-alcance? 100 200 500 500 20))
(display "\n")




;;
;; Ejercicio 6: tipo-triangulo ()
;;

;; Función auxiliar epsilon

(define epsilon 0.0001)

;; Función auxiliar iguales-reales

(define (iguales-reales? x y)
  (< (abs (- x y)) epsilon))

;; Función principal tipo-triangulo 

(define (distancia p1 p2)
  (sqrt
   (+ (expt (- (car p1) (car p2)) 2)
      (expt (- (cdr p1) (cdr p2)) 2))))

(define (tipo-triangulo p1 p2 p3)
  (if (and
       (iguales-reales? (distancia p1 p2) (distancia p2 p3))
       (iguales-reales? (distancia p2 p3) (distancia p3 p1)))
      "equilatero"
      (if (or
           (iguales-reales? (distancia p1 p2) (distancia p2 p3))
           (iguales-reales? (distancia p1 p2) (distancia p3 p1))
           (iguales-reales? (distancia p2 p3) (distancia p3 p1)))
           "isosceles"
           "escaleno")))
(display
(tipo-triangulo (cons 1 1) (cons  1 6) (cons 6 1)))
(display "\n")
(display
(tipo-triangulo (cons -2 3) (cons  2 6) (cons 5 3)))
(display "\n")
(display
(tipo-triangulo (cons -3 0) (cons  3 0) (cons 0 5.1961)))

;;
;; Ejercicio 7: calculadora #
;;
(define (calculadora lista)
  (cond
    ((eq? (car lista) #\+) (+ (car (cdr lista)) (car (cddr lista))))
    ((eq? (car lista) #\-) (- (car (cdr lista)) (car (cddr lista))))
    ((eq? (car lista) #\*) (* (car (cdr lista)) (car (cddr lista))))
    ((eq? (car lista) #\/) (/ (car (cdr lista)) (car (cddr lista))))
    (else "Error")))

(display "\n")
(display (calculadora (list #\+ 3 3)))
(display "//")
(display (calculadora (list #\- 3 3)))
(display "//")
(display (calculadora (list #\* 3 3)))