app([],Y,Y).
app([H|X],Y,[H|Z]) :- app(X,Y,Z).
