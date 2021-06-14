kthfind([A|_],K,A,I) :- K is I.
kthfind([_|L],K,E,I) :- kthfind(L,K,E,J), J is I+1.
kth([A|L],K,E) :- kthfind([A|L],K,E,0).
