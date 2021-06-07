last([X],X).
last([X|Y],L):-last(Y,L).
