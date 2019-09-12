;;Pedro Giménez Aldeguer

#lang r6rs
(import (rnrs)
        (schemeunit)
        (graphics turtles))
;;
;; Ejercicio 1
;;

(define lista-a '((a b) d (c (e) (f g) h)))
(check-equal? (cadddr(caddr lista-a)) 'h)


(define lista-b '(1 (6 (3) 10) (2) 8))
(check-equal? (caddr(cadr lista-b)) 10)

;;
;; Ejercicio 2
;;

;Auxiliar hoja?

(define (hoja? dato)
  (not (list? dato)))

;Funcion Principal a)

(define (cuenta-pares lista)
(if (null? lista)
    0
    (if (hoja? (car lista))
        (if (odd? (car lista))
            (cuenta-pares (cdr lista))
            (+ 1 (cuenta-pares (cdr lista))))
        (+ (cuenta-pares (car lista)) (cuenta-pares (cdr lista))))))

(define (cuenta-pares2 lista)
  (cond
    ((null? lista) 0)
    ((hoja? lista) (if (even? lista) 1 0))
    (else(+ (cuenta-pares2 (car lista))
            (cuenta-pares2 (cdr lista))))))

(display (cuenta-pares '(1 (2 3) 4 (5 6)))) ; ⇒ 3
(display "\n")
(display (cuenta-pares '(((1 2) 3 (4) 5) ((((6))))))) ; ⇒ 3


;Funcion Principal b)

(define (cuenta-pares-fos lista)
  (fold-right + 0 (map (lambda (x) (if (hoja? x)
                                       (if (even? x) 1 0)
#| Va recorriendo todas las hojas |#   (cuenta-pares-fos x))) lista)))
#| Map coge cada grupo de listas y va buscando si es una hoja|#

(display "\n")
(display (cuenta-pares-fos '(1 (2 3) 4 (5 6)))) ; ⇒ 3
(display "\n")
(display (cuenta-pares-fos '(((1 2) 3 (4) 5) ((((6))))))) ; ⇒ 3



;;
;; Ejercicio 3
;;

(define (cumplen-predicado pred lista)
  (cond
    ((null? lista) '())
    ((hoja? lista) (if (pred lista)(list lista)'()))
    (else (append (cumplen-predicado pred (car lista))
                  (cumplen-predicado pred (cdr lista))))))


(display "\n")
(display (cumplen-predicado even? '(1 (2 (3 (4))) (5 6)))) ; ⇒ {2 4 6}
(display "\n")
(display (cumplen-predicado pair? '(((1 . 2) 3 (4 . 3) 5) 6))) ; ⇒ {{1 . 2} {4 . 3}


(define (cumplen-predicado-fos pred lista)
  (fold-right append '() (map (lambda (x)
                              (if (hoja? x)
                                  (if (pred x) (list x) '())
                                  (cumplen-predicado pred x))) lista)))


(display "\n")
(display (cumplen-predicado-fos even? '(1 (2 (3 (4))) (5 6)))) ; ⇒ {2 4 6}
(display "\n")
(display (cumplen-predicado-fos pair? '(((1 . 2) 3 (4 . 3) 5) 6))) ; ⇒ {{1 . 2} {4 . 3}


;;
;; Ejercicio 4
;;


(define (sustituye-elem lista o n)
  (cond ((null? lista) '() )
        ((hoja? lista) (if(equal? o lista) n  lista ))
        (else (cons (sustituye-elem (car lista) o n) (sustituye-elem (cdr lista) o n)))))

(display "\n")
(display (sustituye-elem  '(a b (c d (e c)) c (f (c) g))  'c  'h))
;⇒ {a b {h d {e h}} h {f {h} g}}

;;
;; Ejercicio 5
;;

(define (diff-listas l1 l2)
  (cond ((or (null? l1) (null? l2)) '() )
        ((hoja? l1) (if(not (equal? l1 l2)) (list (cons l1 l2))'() ))
        (else (append (diff-listas (car l1) (car l2))
                      (diff-listas (cdr l1) (cdr l2))))))

(display "\n")
(display (diff-listas '(a (b ((c)) d e) f) '(1 (b ((2)) 3 4) f)))
;⇒ {{a . 1} {c . 2} {d . 3} {e . 4}}

(display "\n")
(display (diff-listas '((a b) c) '((a b) c)))
;⇒ ()


;;
;; Ejercicio 6
;;


;;A)

(define (cuenta-hojas-debajo-nivel lista n)
  (cond ((null? lista) 0)
        ((hoja? lista) (if(< n 0) 1 0))
        (else (+ (cuenta-hojas-debajo-nivel (car lista) (- n 1))
                      (cuenta-hojas-debajo-nivel (cdr lista) n)))))
#| cuando hace cdr sigue con los hijos sin cambiar n|#


;; Pruebas
(display "\n")
(display "Probando 'cuenta-hojas-debajo-nivel'\n")
(check-equal? (cuenta-hojas-debajo-nivel '(10 2 (4 6 (9 3) (8 7) 12) 1) 1) 7)
(check-equal? (cuenta-hojas-debajo-nivel '(10 2 (4 6 (9 3) (8 7) 12) 1) 3) 0)
(define a '(10 2 (4 6 (9 3) (8 7) 12) 1))


;;B)

(define (maximo pareja1 pareja2)
  (if (> (cdr pareja1)
         (cdr pareja2))
         pareja1
         pareja2))

(define (pareja p)
    (cons (car p)
        (+ 1 (cdr p))))

(define (nivel-elemento lista)
  (cond ((null? lista) (cons 0 0))
        ((hoja? lista) (cons lista 0))
        (else (maximo (pareja (nivel-elemento (car lista)))
                      (nivel-elemento (cdr lista))))))
;(2 . 1)-> (3 . 2<-)


;; Pruebas
(display "Probando 'nivel-elemento'\n")
(check-equal? (nivel-elemento '(2 (3))) '(3 . 2))
(check-equal? (nivel-elemento '((2) (3 (4)((((((5))) 6)) 7)) 8)) '(5 . 8))









