#lang racket

; (append '(1 2 3) '(4 5 6))
(define append
  (lambda (l m)
    (if (null? l) m
        (cons (car l)
              (append (cdr l) m)))))

; (reverse '(1 2 3 4 5 6))
(define reverse
  (lambda (l)
    (if (null? l) l
        (append (reverse (cdr l)) (list (car l))))))