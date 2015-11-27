#lang racket
;16 ((iter (lambda (x) (* x x)) 4) 2)
(define iter
  (lambda (f n)
  (cond ((eq? n 0) (lambda (x) x))
        ((eq? n 1) f)
        (else
          (lambda (x) (f ((iter f (- n 1)) x)))
        )
    )
  )
)

;17a - undefined
(define prod
  (lambda (l)
    (foldl (lambda (a b) (- a b)) 0 l)))

;17b (length '(a b c d e f))
(define length
  (lambda (l)
    (foldl (lambda (item acc) (+ acc 1)) 0 l)))

;17c (member 23 '(1 2 3 4 5 6 7 8))
(define member
  (lambda (x l)
    (foldl (lambda (item acc) (if (eq? item x) #t acc)) #f l)))

;17d - undefined
(define delete
  (lambda (l)
    (foldl (lambda (item acc) (cons item acc)) '() l)))

;17e (reverse '(1 2 3 4 5 6 7 8))
(define reverse
  (lambda (l)
    (foldl (lambda (item acc) (cons item acc)) '() l)))

;19 is atom
(define (atom? x)
  (and (not (null? x))
       (not (pair? x))))
;19a
(define onlyAtoms?
  (lambda (l)
    (foldl (lambda (item acc) (if (atom? item) #t acc)) #f l)))

;19b
(define countAtoms
  (lambda (l)
    (foldl (lambda (item acc) (if (atom? item) (+ acc 1) acc)) 0 l)))

;20
; (member2 '1 '(1 2 3 4 5 (a b c) (b) (a c (b d))))
; (member2 'c '(1 2 3 4 5 (a b c) (b) (a c (b d))))
; (member2 '(b) '(1 2 3 4 5 (a b c) (b) (a c (b d))))
; (member2 '(b d) '(1 2 3 4 5 (a b c) (b) (a c (b d))))
(define member2
  (lambda (x l)
    (foldl (lambda (item acc)
             (cond
               ((eq? item x) #t)
               ((not (atom? item)) (if (eq? (member2 x item) #f) acc #t))
               (else acc))) #f l)))


;21 - Proszę powiększać funkcję deriv tak,
; żeby też mogła traktować termy typu u^n (na podstawie d(u^n) / dx = n * u^(n-1) * du / dx ). 


;22
















