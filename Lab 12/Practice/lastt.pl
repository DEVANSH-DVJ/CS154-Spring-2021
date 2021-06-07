lastt([X],X).
lastt([X|Y],L) :- lastt(Y,L).
