;; Pedro Giménez Aldeguer

#lang r6rs
(import (rnrs)
        (schemeunit))

;;
;; Ejercicio 1: Máximo de una lista
;;


;; Funcion auxiliar mayor

(define (mayor x y)
  (if (> x y)
      x
      y))

;; Función principal máximo

(define (máximo lista)
  (if (null? lista)
      'error
      (if (null? (cdr lista))
          (car lista)
          (mayor(car lista) (máximo(cdr lista))))
      )
  )

(display (máximo '(9 8 6 4 3))) ; ⇒ 9
(display "//")
(display (máximo '(1 -1 3 6 4))) ; ⇒ 6
(display "\n")

(check-equal? (máximo '(9 8 6 4 3)) 9)
(check-equal? (máximo '(1 -1 3 6 4)) 6)




;;
;; Ejercicio 2: a)Pertenece? b)Repetidos
;;


;; Funcion principal pertenece

(define (pertenece? elem lista)
  (if (null? lista)
      #f
      (or(equal? elem (car lista))
         (pertenece? elem (cdr lista)))))
      
(display (pertenece? 'a '(b c d e))) ; ⇒ #f
(display "//")
(display (pertenece? 10 '(1 20 10 40 10))) ; ⇒ #t
(display "\n")

(check-equal? (pertenece? 'a '(b c d e)) #f)
(check-equal? (pertenece? 10 '(1 20 10 40 10)) #t)

;; Función principal repetidos

(define (repetidos? lista)
  (if (null? lista)
      #f
      (or(pertenece? (car lista) (cdr lista))
         (repetidos?(cdr lista)))))

(display (repetidos? '(1 2 3 5 4 5 6))) ; ⇒ #t
(display "//")
(display (repetidos? '(adios hola que tal))) ; ⇒ #f
(display "\n")

(check-equal? (repetidos? '(adios hola que tal)) #f)
(check-equal? (repetidos? '(adios hola que tal)) #f)




;;
;; Ejercicio 3: Box & Pointer a)b)c)d)
;;

;; Ejercicio a)

;P1
(define p1 (list (cons 1 2) 3))
(display p1)
(display "\n")
;P2
(define p2 (list (list #\a #\b)))
(display p2)
(display "\n")
;P3
(define p3 (cons 4 (cons p1 (cons p2 5))))
(display p3)
(display "\n")

;; Ejercicio b)

;P1:
;Es una lista con 2 elementos
;P2:
;Es una lista de 1 elemento
;P3:
;Es una pareja con 3 elementos

;; Ejercicio c)

;1

(display (car(cdr(car(cdr p3)))))
(display "\n")
;2
(display (cdr(cdr(cdr p3))))
(display "\n")

;; Ejercicio d)

(define p4 (list (cons (cons 1 2) (cons 3 4)) (list 5 6 (cons 7 (cons 8 9))) 10))
(display p4)
(display "\n")



;;
;; Ejercicio 4: binario-a-decimal
;;

;; Función principal binario-a-decimal

(define (binario-a-decimal lista)
  (if (null? lista)
     0
     (+ ( * (car lista) (expt 2 (-(length lista)1))) (binario-a-decimal (cdr lista)))))


(display "\n")
(display (binario-a-decimal '(1 1 1 1)))
(display "//")
(display (binario-a-decimal '(1 1 0)))
(display "\n")

(check-equal? (binario-a-decimal '(1 1 1 1)) 15)
(display "//")
(check-equal? (binario-a-decimal '(1 1 0)) 6)

;;
;; Ejercicio 5: ordenada-creciente?
;;

;; Función principal ordenada-creciente?

(define (ordenada-creciente? lista)
  (if (null? (cdr lista))
      #t
      (if (< (car lista) (cadr lista))
            (ordenada-creciente? (cdr lista))
            #f)))
            

(display (ordenada-creciente? '(-1 23 45 59 99)))  ; ⇒ #t
(display (ordenada-creciente? '(12 50 -1 293 1000)))  ; ⇒ #f
(display (ordenada-creciente? '(3)))  ; ⇒ #t



;;
;; Ejercicio 6: a)(inc-izq pareja)(inc-der pareja) b)(cuenta-impares-pares)
;;

;; Función principal a)(inc-izq pareja)(inc-der pareja)

(define (inc-izq pareja)
  cons (+(car pareja)1) cdr pareja)


(define (inc-der pareja)
  cons (car pareja) (+(cdr pareja)1))

;; Función principal b)(cuenta-impares-pares)

(define (cuenta-impares-pares lista)
  (if (null? lista)
     (cons 0 0)
      (if(even? car lista)
         (inc-izq(cons  (cuenta-impares-pares (cdr lista)) 0))
         (inc-der(cons 0  (cuenta-impares-pares (cdr lista))))      
         )))

(display "\n")
(display (inc-izq (cons 10 20)))  ; ⇒ {11 . 20}
(display "//")
(display (inc-der (cons 10 20)))  ; ⇒ {10 . 21}

;;
;; Ejercicio 7: cadena-mayor
;;

;; Función auxiliar mayor2

(define (mayor2 p1 p2)
  (if (> (cdr p1) (cdr p2))
      p1
      p2))

;; Función principa cadena-mayor

(define (cadena-mayor lista)
   (if (null? lista)
      (cons "" 0)
      (if (null? (cdr lista))
          (cons (car lista) (string-length (car lista)))
          (mayor2 (cons (car lista) (string-length (car lista))) (cadena-mayor (cdr lista))))))





