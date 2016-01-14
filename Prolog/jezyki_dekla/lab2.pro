% http://swish.swi-prolog.org/
% Zad 5.a
delete1(X,[X|L1], L1).
delete1(X,[Y|L1],[Y|L2]) :- delete1(X, L1, L2).

% Zad 5.b
delete2([_,_,_], []).
delete2([Y|L1],[Y|L2]) :- delete2(L1, L2).

% Zad 5.c
p(X, [], nil, nil).
p(X, [A,X,B], A, B).
p(X, [A,X,B|_], A, B).
p(X, [_|P], A, B) :- p(X, P, A, B).

% Zad 5.d
% q(X, [], []).
q(X, [X,X], [X,X]).
q(X, [X,X|_], [X,X]).
q(X, [Y|L1],[Y|L2]) :- 
    q(X, L1, L2).

% Zad 5.e
oddlength([_]).
evenlength([_|L]) :- oddlength(L).
oddlength([_|L]) :- evenlength(L).

