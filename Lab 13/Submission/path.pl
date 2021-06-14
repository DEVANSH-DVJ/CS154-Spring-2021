connected(delhi,mumbai).
connected(mumbai,bangalore).
connected(bangalore,chennai).
connected(bhubaneswar,kolkata).
connected(kolkata,patna).

path(A,B) :- connected(A,B).
path(A,C) :- connected(A,B), path(B,C).
