kthfind([A|_],K,A,I) :- K is I.
kthfind([_|L],K,E,I) :- J is I+1, kthfind(L,K,E,J).
kth([A|L],K,E) :- kthfind([A|L],K,E,0).
