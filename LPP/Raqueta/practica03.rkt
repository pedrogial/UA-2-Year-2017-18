;; Pedro Gimenez Aldeguer

#lang r6rs
(import (rnrs)
        (schemeunit))

;;
;; Ejercicio 1: Multiplo-de
;;

;; Funcion principal

(define (multiplo-de n lista)
  (if(null? lista)
     '()
     (cons (= (mod (car lista) n) 0) (multiplo-de n(cdr lista)))))


(display (multiplo-de 10 '(100 23 10 300  48 7))) ; ⇒ (#t #f #t #t #f #f)
(display "\n")

;;
;; Ejercicio 2: Calcular-lista
;;

;; Funcion principal

(define (calcular-lista lista)
  (cond ((null? lista) '())
        ((equal? '+ (car lista)) (cons (+(caadr lista)(cdadr lista))(calcular-lista (cddr lista))))
        ((equal? '- (car lista)) (cons (-(caadr lista)(cdadr lista))(calcular-lista (cddr lista))))
        ((equal? '* (car lista)) (cons (*(caadr lista)(cdadr lista))(calcular-lista (cddr lista))))
        ((equal? '/ (car lista)) (cons (/(caadr lista)(cdadr lista))(calcular-lista (cddr lista))))
        (else 'error)))

(display (calcular-lista '(+ (2 . 3) * (4 . 5)))) ; ⇒ {5 20}
(display "//")
(display (calcular-lista '(/ (-6 . 2) - (4.5 . 0.5) + (2 . 3)))) ; ⇒ {-3 4.0 5}
(display "\n")



;;
;; Ejercicio 3: expande
;;

;; Funcion auxiliar

(define (expand p)
  (if(= (cdr p) 0)
     '()
     (cons (car p) (expand (cons (car p) (-(cdr p) 1))))))

;; Funcion principal

(define (expande lista)
  (if(null? lista)
     '()
     (append (expand (car lista)) (expande (cdr lista)))))

(display (expande '((#t . 3) ("LPP" . 2) (b . 4)))) ;⇒ {#t #t #t "LPP" "LPP" b b b b}
(display "\n")



;;
;; Ejercicio 4: resultados-quiniela//cuenta-resultado//cuenta-resultado-lista//
;;

;;a)resultados-quiniela

(define (resultados-quiniela lista)
  (cond ((null? lista) '())
        ((> (caar lista) (cdar lista)) (cons 1 (resultados-quiniela (cdr lista))))
        ((< (caar lista) (cdar lista)) (cons 2 (resultados-quiniela (cdr lista))))
        (else (cons 'X (resultados-quiniela (cdr lista))))))

(display (resultados-quiniela '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9))))  ; ⇒ {2 X 2 1 X}
(display "//")
(display (resultados-quiniela '((2 . 2)))) ; ⇒ {X}
(display "//")
(display (resultados-quiniela '((3 . 2) (4 . 3) (3 . 5))))  ; ⇒ {1 1 2}
(display "\n")


;;b)cuenta-resultados

(define (cuenta-resultados x lista)
  (if (null? lista)
    0
    (if (equal? (resultados-quiniela (cons(car lista) '())) (cons x '()))
        (+ 1 (cuenta-resultados x (cdr lista)) )
        (cuenta-resultados x (cdr lista)) )))

(display(cuenta-resultados 'X '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 2
(display "//")
(display(cuenta-resultados 1 '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 1
(display "//")
(display(cuenta-resultados 2 '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 2
(display "\n")

;;c)cuenta-resultado-lista

(define (inc-pos n lista)
  (if (= n 0)
      (cons (+ 1 (car lista)) (cdr lista))
      (cons (car lista) (inc-pos (- n 1) (cdr lista)))))

(define (resultado-partido partido)
  (cond
    ((> (car partido) (cdr partido))  1)
    ((= (car partido) (cdr partido))  'X)
    (else 2)))

(define (cuenta-resultados-lista lista-resultados)
  (cond
    ((null? lista-resultados) (list 0 0 0))
    ((equal? 1 (resultado-partido (car lista-resultados)))
     (inc-pos 0 (cuenta-resultados-lista (cdr lista-resultados))))    
    ((equal? 'X (resultado-partido (car lista-resultados)))
     (inc-pos 1 (cuenta-resultados-lista (cdr lista-resultados))))
    (else (inc-pos 2 (cuenta-resultados-lista (cdr lista-resultados))))))
  

(display (cuenta-resultados-lista '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ {1 2 2}
(display "//")
(display (cuenta-resultados-lista '((2 . 2)))) ; ⇒ {0 1 0}
(display "//")
(display (cuenta-resultados-lista '((3 . 2) (4 . 3) (3 . 5))))  ; ⇒ {2 0 1}
(display "\n")



;;
;; Ejercicio 5: filtrar-simbolos
;;

;; Funcion principal

(define (filtra-simbolos lista numero)
  (if(null? lista)
     '()
      (if(= (string-length(symbol->string(car lista))) (car numero))
         (cons (cons (car lista) (car numero)) (filtra-simbolos (cdr lista)(cdr numero)))
         (filtra-simbolos (cdr lista)(cdr numero)))))
    
(display (filtra-simbolos '(este es un ejercicio de examen) '(2 1 2 9 1 6)))
; ⇒ {{un . 2} {ejercicio . 9} {examen . 6}}