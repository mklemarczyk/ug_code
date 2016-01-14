
#lang racket

;; http://docs.racket-lang.org/reference/let.html

;;; Queues

;;; Representaton of queues

(define (front-ptr queue) (mcar queue))

(define (rear-ptr queue) (mcdr queue))

(define (set-front-ptr! queue item) (set-mcar! queue item))

(define (set-rear-ptr! queue item) (set-mcdr! queue item))

;;; Operations on queues

(define (empty-queue? queue) (null? (front-ptr queue)))

(define (make-queue) (mcons '() '()))

(define (front queue)
  (if (empty-queue? queue)
      (error "FRONT called with an empty queue" queue)
      (mcar (front-ptr queue))))

(define (insert-queue! queue item)
  (let ((new-pair (mcons item '())))
    (cond ((empty-queue? queue)
           (set-front-ptr! queue new-pair)
           (set-rear-ptr! queue new-pair)
           queue)
          (else
           (set-mcdr! (rear-ptr queue) new-pair)
           (set-rear-ptr! queue new-pair)
           queue)))) 

(define (delete-queue! queue)
  (cond ((empty-queue? queue)
         (error "Delete called with an empty queue" queue))
        (else
         (set-front-ptr! queue (mcdr (front-ptr queue)))
         queue))) 




;;; Digial-circuit simulator

(define (half-adder a b s c)
  (let ((d (make-wire)) (e (make-wire)))
    (or-gate a b d)
    (and-gate a b c)
    (inverter c e)
    (and-gate d e s))
    'half-adder)
 
(define (inverter input output)
   (define (invert-input)
      (let ((new-value (logical-not (get-signal input))))
         (after-delay inverter-delay 
                      (lambda ()
                         (set-signal! output new-value)))))
  (add-action! input invert-input))

(define (logical-not s)
  (cond ((= s 0) 1)
        ((= s 1) 0)
        (else (error "Invalid signal" s))))


(define (and-gate a1 a2 output)
  (define (and-action-procedure)
    (let ((new-value
           (logical-and (get-signal a1) (get-signal a2))))
      (after-delay and-gate-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  (add-action! a1 and-action-procedure)
  (add-action! a2 and-action-procedure))

(define (logical-and s1 s2)
   (cond ((not (or (= s1 0) (= s1 1))) (error "Invalid signal" s1))
         ((not (or (= s2 0) (= s2 1))) (error "Invalid signal" s2))
         ((and (= s1 1) (= s2 1))      1)
         (else                         0)))


(define (or-gate a1 a2 output)
  (define (or-action-procedure)
    (let ((new-value
           (logical-or (get-signal a1) (get-signal a2))))
      (after-delay or-gate-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  (add-action! a1 or-action-procedure)
  (add-action! a2 or-action-procedure))

(define (logical-or s1 s2)
   (cond ((not (or (= s1 0) (= s1 1))) (error "Invalid signal" s1))
         ((not (or (= s2 0) (= s2 1))) (error "Invalid signal" s2))
         ((and (= s1 0) (= s2 0))      0)
         (else                         1)))

(define (full-adder a b c-in sum c-out)
  (let ([s (make-wire)] [c1 (make-wire)] [c2 (make-wire)])
    (half-adder b c-in s c1)
    (half-adder a s sum c2)
    (or-gate c1 c2 c-out)))

;;; Wires 

(define (make-wire)
  (let ((signal-value 0) (action-procedures '()))
    
    (define (set-my-signal! new-value)
      (if (not (= signal-value new-value))
          (begin (set! signal-value new-value)
                 (call-each action-procedures))
          '()))

    (define (accept-action-procedure proc)
      (set! action-procedures (cons proc action-procedures))
      (proc))

    (define (dispatch m)
      (cond ((eq? m 'get-signal) signal-value)
            ((eq? m 'set-signal!) set-my-signal!)
            ((eq? m 'add-action!) accept-action-procedure)
            (else (error "Unknown operation -- WIRE" m))))

    dispatch))

(define (call-each procedures)
  (if (not (null? procedures))
      (begin
       ((car procedures))
       (call-each (cdr procedures)))
      '()))

(define (get-signal wire)
  (wire 'get-signal))

(define (set-signal! wire new-value)
  ((wire 'set-signal!) new-value))

(define (add-action! wire action-procedure)
  ((wire 'add-action!) action-procedure))



;;; Agenda use

(define (after-delay delay action)
  (add-to-agenda! (+ delay (current-time the-agenda))
                  action
                  the-agenda))



;;; Top level of simulation

(define (propagate)
  (if (empty-agenda? the-agenda)
      'done
      (let ((first-item (first-agenda-item the-agenda)))
        (first-item)
        (remove-first-agenda-item! the-agenda)
        (propagate))))



;;; Probing a wire

(define (probe name wire)
  (add-action! wire
               (lambda ()        
                  (print name)
                  (display ": New value = ")
                  (print (get-signal wire))
                  (display " at time ")
                  (print (current-time the-agenda))
                  (newline))))









;;; Implementation of the agenda

(define (make-time-segment time queue) (mcons time queue))

(define (segment-time s) (mcar s))

(define (segment-queue s) (mcdr s))

(define (make-agenda)
  (mcons '*agenda*
         (mcons (make-time-segment 0 (make-queue))
                '())))

(define (segments agenda) (mcdr agenda))

(define (first-segment agenda) (mcar (segments agenda)))

(define (rest-segments agenda) (mcdr (segments agenda)))

(define (set-segments! agenda segments) (set-mcdr! agenda segments))

(define (current-time agenda) (segment-time (first-segment agenda)))

(define (empty-agenda? agenda)
  (and (empty-queue? (segment-queue (first-segment agenda)))
       (null? (rest-segments agenda))))

(define (add-to-agenda! time action agenda)
  (define (add-to-segments! segments)
    (if (= (segment-time (mcar segments)) time)
        (insert-queue! (segment-queue (mcar segments))
                       action)
        (let ((rest (mcdr segments)))
          (cond ((null? rest)
                 (insert-new-time! time action segments))
                ((> (segment-time (mcar rest)) time)
                 (insert-new-time! time action segments))
                (else (add-to-segments! rest))))))
  (add-to-segments! (segments agenda)))

(define (insert-new-time! time action segments)
  (let ((q (make-queue)))
    (insert-queue! q action)
    (set-mcdr! segments
              (mcons (make-time-segment time q)
                     (mcdr segments)))))

(define (remove-first-agenda-item! agenda)
  (delete-queue! (segment-queue (first-segment agenda))))

(define (first-agenda-item agenda)
  (let ((q (segment-queue (first-segment agenda))))
    (if (empty-queue? q)
        (begin (set-segments! agenda
                                 (rest-segments agenda))
                  (first-agenda-item agenda))
        (front q))))



;;; Sample simulation 

(define the-agenda (make-agenda))
(define inverter-delay 2)
(define and-gate-delay 3)
(define or-gate-delay 5)

(define input-1 (make-wire))
(define input-2 (make-wire))
(define c-in (make-wire))
(define sum (make-wire))
(define carry (make-wire))

(probe 'sum sum)
(probe 'carry carry)

(full-adder input-1 input-2 c-in sum carry)

(set-signal! input-1 1)
(propagate)

(set-signal! input-2 1)
(propagate) 

(set-signal! c-in 1)
(propagate)
(newline)

;Complex simulation
(define a1 (make-wire))
(define a2 (make-wire))
(define a3 (make-wire))
(define a4 (make-wire))
(define b1 (make-wire))
(define b2 (make-wire))
(define b3 (make-wire))
(define b4 (make-wire))
(define s1 (make-wire))
(define s2 (make-wire))
(define s3 (make-wire))
(define s4 (make-wire))
(define c (make-wire))

(define (ripple-carry-adder A B S c) ; New cable is neede to prevent loop infinity
  (if (= (length A) 1) (begin (probe 'carry c) (half-adder (car A) (car B) (car S) c))
        (let ([c-in (make-wire)])
                (full-adder (car A) (car B) c-in (car S) c)
                (ripple-carry-adder (cdr A) (cdr B) (cdr S) c-in))
        ))

(probe 's1 s1)
(probe 's2 s2)
(probe 's3 s3)
(probe 's4 s4)


(ripple-carry-adder (list a3 a2 a1 a0) (list b3 b2 b1 b0) (list s3 s2 s1 s0) c)

(set-signal! a3 1)
(set-signal! a2 0)
(set-signal! a1 1)
(set-signal! a0 1)

(set-signal! b3 0)
(set-signal! b2 0)
(set-signal! b1 1)
(set-signal! b0 1)
(propagate)

