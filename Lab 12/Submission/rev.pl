rev([],[]).
rev([H|T],R) :- rev(T,Tr), append(Tr,[H],R).
