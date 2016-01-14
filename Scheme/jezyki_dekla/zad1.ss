#lang racket

(define nwd
  (lambda (a b)
    (cond ((> a b) (nwd (- a b) b))
          ((< a b) (nwd (- b a) a))
          (else a))))


(define nww
  (lambda (a b)
    (/ (* a b) (nwd a b))))




(define new.<
  (lambda (x y)
    (< x y)))

(define new.>
  (lambda (x y)
    (< y x)))

(define new.=
  (lambda (x y)
    (not (or (< x y) (< y x)))))

(define new.<=
  (lambda (x y)
    (not (< y x))))

(define new.>=
  (lambda (x y)
    (not (< x y))))

(define new.<>
  (lambda (x y)
    (or (< x y) (< y x))))


(define same-values?
  (lambda (p1 p2 x y)
    (equal? (p1 x y) (p2 x y))))



(define odd-help?
  (lambda (n x)
    (if (zero? n)
        (zero? x)
        (if (zero? x)
            (odd-help? (- n 1) (+ x 1))
            (odd-help? (- n 1) (- x 1))
         ))))

(define odd?
  (lambda (n)
    (odd-help? n 1)))

(define even?
  (lambda (n)
    (odd-help? n 0)))

;6
(define fib
  (lambda (n)
    (cond ((= n 0) 0)
          ((= n 1) 1)
          (else (+ (fib (- n 1)) (fib (- n 2))))
          )))

;7
(define exp
  (lambda (b e)
    (cond ((= e 0) 1)
          ((= e 1) b)
          (else (* (exp b (/ e 2)) (exp b (/ e 2))))
          )
    )
 )

;8
(define n 1)
(define (q n)
  (define (qq x)
    (+ x n))
  (qq 5))
;(q 11) = 16

(define m 1)
(define (p m)
   (pp 5))
(define (pp x)
   (+ x m))
;(p 11) = 6

;9
(define product
  (lambda (term a next b)
    (if (> a b)
        1
        (* (term a) (product term (next a) next b)))))


; silnia 7
; (product (lambda (n) n) 1 (lambda (n) (+ n 1)) 7)

; przyblizenie 20
; (* (product (lambda (n) (/ (* (+ n 1) (+ n 3)) (* (+ n 2) (+ n 2)))) 1 (lambda (n) (+ n 2)) 2) 40)



;14a (append l m), która konkatenuje listy l i m.
(define append
  (lambda (l m)
    (if 
        (empty? m) l
        (append (cons (car m) l) (list-tail m 1)))))

;14b (reverse l), która obróci listę l.
(define reverse
  (lambda (l)
    (cond ((empty? l) l)
          (else (append '() l)))))
;14c (last l), która znajduje ostatni element w liscie l.
(define last
  (lambda (l)
    (cond ((empty? l) #f)
          ((empty? (list-tail l 1)) (car l))
          (else (last (list-tail l 1))))))

;14d (delete x l), która skasuje element x z listy l.
(define delete-help
  (lambda (x l t)
    (if 
        (empty? l) t
        (if (= (car l) x)
        (delete-help x (list-tail l 1) t)
        (delete-help x (list-tail l 1) (cons (car l) t))))))
(define delete
  (lambda (x l)
    (reverse (delete-help x l '()))))

;15a Proszę napisać funkcję (square-list l), której wartość jest listą kwadratów elementów listy l. 
(define square-list-help
  (lambda (l t)
    (if 
        (empty? l) t
        (square-list-help (cdr l) (cons (* (car l) (car l)) t)))))
(define square-list
  (lambda (l)
    (reverse (square-list-help l '()))))

;15b Proszę napisać funkcję (mapf f l), której wartością jest lista wartości f(e) dla wszystkich elementów e w liscie l.
(define mapf-help
  (lambda (f l t)
    (if 
        (empty? l) t
        (mapf-help f (cdr l) (cons (f (car l)) t)))))
(define mapf
  (lambda (f l)
    (reverse (mapf-help f l '()))))







