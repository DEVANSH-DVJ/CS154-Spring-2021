cnt([],_,0).
cnt([X|T],X,Y) :- cnt(T,X,Z), Y is Z+1.
cnt([X1|T],X,Z) :- cnt(T,X,Z), X1 \= X.
