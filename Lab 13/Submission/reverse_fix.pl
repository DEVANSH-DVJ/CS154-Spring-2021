app([],Y,Y).
app([H|X],Y,[H|Z]) :- app(X,Y,Z).

rev([],[]).
rev([H|T],R) :- rev(T,Tr), app(Tr,[H],R).
