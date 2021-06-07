len([],0).
len([H|T],N):-len(T,M), N is 1+M.
%list is represented as [head|tail]
%head is an element
%tail is rest of the list-- not an element
