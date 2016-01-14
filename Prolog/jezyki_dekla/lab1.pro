% http://swish.swi-prolog.org/
% Zad 1
myLength([],0).
myLength([X|L],M) :- myLength(L,N), M is N+1.

myFib(1,1).
myFib(2,1).
myFib(X,N) :- Xdec1 is X-1, Xdec2 is X-2, myFib(Xdec1, Np1), myFib(Xdec2, Np2), N is Np1+Np2.

% Zad 4
% Niech będzie dany następujący program.  f(1,one).
 f(s(1),two).
 f(s(s(1)),three).
 f(s(s(s(X))),N) :- f(X,N). 
% Jak odpowiada Prolog na pytanie 
% a. f(s(1),A)? 
% A = two
% b. f(s(s(1)),two)? 
% false
% c. f(s(s(s(s(s(s(1)))))),C)? 
% C=one
% d. f(D,three)? 
% D = s(s(1))
% e. f(s(s(s(s(s(s(X)))))),E)? 
% E = one, X = 1
