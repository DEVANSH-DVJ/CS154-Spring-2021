ismember(X,[X|T]).
ismember(X,[Y|T]) :- ismember(X,T).
