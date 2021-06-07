min([X],X).
min([H,K|T],M) :- min([H|T],M), H =< K.
min([H,K|T],M) :- min([K|T],M), H > K.
