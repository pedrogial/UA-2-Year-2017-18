;; Pedro Gimenez Aldeguer

#lang r6rs
(import (rnrs)
        (schemeunit))

;;
;;Ejercicio 1
;;

;;Funcion Principal (longitud-impar lista-simbolos)

(define (longitud-impar2 lista)
   (filter (lambda (l)
              (odd? (string-length (symbol->string l)))) lista))

;;Funcion Principal (suma-longitudes lista-simbolos)

(define (suma dato resultado)
    (+ (string-length(symbol->string dato)) resultado))

(define (suma-longitudes lista)
   (fold-right suma 0 lista))

;;Funcion Principal (mayusculas lista-simbolos)

(define (mayusculas lista)
   (map (lambda (l)
              (string->symbol(string-upcase(symbol->string l)))) lista))


(display (longitud-impar2 '(me gusta LPP porque aprendo nuevos paradigmas de programación)))
; ⇒ {gusta LPP aprendo}
(display "\n")
(display (suma-longitudes '(me gusta LPP porque aprendo nuevos paradigmas de programación)))
; ⇒ 53
(display "\n")
(display (mayusculas '(me gusta LPP porque aprendo nuevos paradigmas de programación)))
; ⇒ {ME GUSTA LPP PORQUE APRENDO NUEVOS PARADIGMAS DE PROGRAMACIÓN}




;;
;;Ejercicio 2
;;

;;A(resultados‐quiniela lista‐parejas)

;(define (resultados-quiniela lista)
 ; (cond ((null? lista) '())
  ;      ((> (caar lista) (cdar lista)) (cons 1 (resultados-quiniela (cdr lista))))
   ;     ((< (caar lista) (cdar lista)) (cons 2 (resultados-quiniela (cdr lista))))
    ;    (else (cons 'X (resultados-quiniela (cdr lista))))))

(define (resultados-quiniela lista)
   (map simbolos lista))

(define (simbolos p)
  (cond ((> (car p) (cdr p)) 1)
        ((< (car p) (cdr p)) 2)
        (else 'X)))


(display "\n")
(display (resultados-quiniela '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9))))  ; ⇒ {2 X 2 1 X}
(display (resultados-quiniela '((2 . 2)))) ; ⇒ {X}
(display (resultados-quiniela '((3 . 2) (4 . 3) (3 . 5))))  ; ⇒ {1 1 2}

;;B(cuenta-resultados resultado lista-resultados)


;(define (cuenta-resultados x lista)
 ; (if (null? lista)
  ;  0
   ; (if (equal? (resultados-quiniela (cons(car lista) '())) (cons x '()))
    ;   (+ 1 (cuenta-resultados x (cdr lista)) )
    ;    (cuenta-resultados x (cdr lista)) )))


(define (cuenta-resultados x lista)
  (fold-right suma2 0 (filter (lambda (l)
                                (equal? x l))(map simbolos lista))))

(define (suma2 dato resultado)
    (+ 1 resultado))

(display "\n")
(display (cuenta-resultados 'X '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 2
(display "//")
(display (cuenta-resultados 1 '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 1
(display "//")
(display (cuenta-resultados 2 '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ 2
(display "\n")

;;C(cuenta-resultados-lista lista-resultados)

(define (inc-pos n lista)
  (if (= n 0)
      (cons (+ 1 (car lista)) (cdr lista))
      (cons (car lista) (inc-pos (- n 1) (cdr lista)))))

(define (resultado-partido partido)
  (cond
    ((> (car partido) (cdr partido))  1)
    ((= (car partido) (cdr partido))  'X)
    (else 2)))

(define (cuenta-resultados-lista lista)
  (fold-right proceso (list 0 0 0)(map resultado-partido lista)))

(define (proceso dato resultado)
  (cond
    ((equal? 1 dato)
    (inc-pos 0 resultado))    
    ((equal? 'X dato)
    (inc-pos 1 resultado))
    (else (inc-pos 2 resultado))))

(display (cuenta-resultados-lista '((1 . 2) (4 . 4) (3 . 5) (6 . 2) (9 . 9)))) ; ⇒ {1 2 2}
(display (cuenta-resultados-lista '((2 . 2)))) ; ⇒ {0 1 0}
(display (cuenta-resultados-lista '((3 . 2) (4 . 3) (3 . 5))))  ; ⇒ {2 0 1}
(display "\n")



;;
;;Ejercicio 3
;;

;;a)
(fold-right list 0 '(1 2 3))
; ⇒ {1 {2 {3 0}}}

;;b)
(fold-left list "hola" '("como" "estas" "adios"))
; ⇒ {{{"hola" "como"} "estas"} "adios"}

;;c)
(define lista '((2 . 7) (3 . 5) (10 . 4) (5 . 5)))
(filter even?
        (map (lambda (x) (+ (car x)
                            (cdr x)))
             lista))
; ⇒ {8 14 10}

;;d)
(define (invertir lista)
  (cons(cdr lista) (car lista)))

(filter (lambda (x) (> (car x)
                            (cdr x)))
        (map  invertir lista))
; ⇒ {{7 . 2} {5 . 3}}

;;e)
(define (primer dato resultado)
  (cons(car dato) resultado))

(fold-right primer '()
       ( filter   (lambda (x) (even? (+ (car x) (cdr x)))) lista))
; ⇒ {3 10 5}



;;
;;Ejercicio 4
;;

;;Funcion Principal A)
(define (construye-sumador k)
   (lambda (x)
       (+ x k)))

(define (construye-multiplicador k)
  (lambda (x)
       (* x k)))
(define (construye-exponenciador k)
  (lambda (x)
       (expt k x)))



(define multiplica-por-10 (construye-multiplicador 10))
(display (multiplica-por-10 3)) ; ⇒ 30
(display "//")
(define multiplica-por-5 (construye-multiplicador 5))
(display (multiplica-por-5 3)) ; ⇒ 15
(display "//")
(define elevado-2-a (construye-exponenciador 2))
(display (elevado-2-a 3)) ; ⇒ 8
(display "//")
(define elevado-5-a (construye-exponenciador 5))
(display (elevado-5-a 3)) ; ⇒ 125

;;Funcion Principal B)

(define (fija-arg f i k)
  (lambda (x)
       (if(= i 1)
          (f k x)
          (f x k))))

(display "\n")
(define suma-10 (fija-arg + 2 10))
(display(suma-10 8)) ; ⇒ 18
(display "//")
(define elevado-3-a (fija-arg expt 1 3))
(display(elevado-3-a 5)) ; ⇒ 243
(display "//")
(define añade-asteriscos (fija-arg string-append 2 "****"))
(display(añade-asteriscos "Hola")) ; ⇒ "Hola****"
(display "//")
(define precede-asteriscos (fija-arg string-append 1 "****"))
(display(precede-asteriscos "Hola")) ; ⇒ "****Hola"
(display "\n")



;;
;;Ejercicio 5
;;

;;Funcion Principal A)
(define (suma-n-izq n p)
  (map (lambda (p)
         (cons (+(car p) n) (cdr p))) p))

(display (suma-n-izq 10 '((1 . 3) (0 . 9) (5 . 8) (4 . 1))))
; ⇒ {{11 . 3} {10 . 9} {15 . 8} {14 . 1}}


;;Funcion Principal B)
(define (aplica-2 f l)
  (map (lambda (p)
         (f (car p) (cdr p))) l))


(display "\n")
(display (aplica-2 + '((2 . 3) (1 . -1) (5 . 4))))
 ;⇒ {5 0 9}

(display "//")
(display (aplica-2 (lambda (x y)
             (if (even? x)
                 y
                 (* y -1))) '((2 . 3) (1 . 3) (5 . 4) (8 . 10))))
; ⇒ {3 -3 -4 10}


;;
;;Ejercicio 6
;;

;;Funcion Principal A)
(define (cadena-mayor lista)
  (fold-right (lambda (dato res)
                (if (> (cdr dato) (cdr res))
                    dato
                    res))
              (cons "" 0)
              (map(lambda (x) (cons x (string-length x))) lista)))

(display "\n")
(display (cadena-mayor '("vamos" "a" "obtener" "la" "cadena" "mayor"))) ; ⇒  {"obtener" . 7}  
(display (cadena-mayor '("prueba" "con" "maximo" "igual"))) ; ⇒ {"maximo" . 6} 
(display (cadena-mayor '("hola"))) ; ⇒ {"hola" . 4}

;;Funcion Principal B)

;(map (lambda (x y)
;        (+ x y)) '(1 2 3 4) '(4 4 4 4))
; ⇒ {5 6 7 8}
  
(define (filtra-simbolos lista numero)
 (filter (lambda (l) (if (null? l) #f #t))  (map (lambda (x y)
        (if(= (string-length(symbol->string x)) y)
           (cons x y)
           '())) lista numero)))

(display "\n")
(display (filtra-simbolos '(este es un ejercicio de examen) '(2 1 2 9 1 6)))
; ⇒ {{un . 2} {ejercicio . 9} {examen . 6}}