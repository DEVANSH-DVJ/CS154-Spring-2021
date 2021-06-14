connected(delhi,mumbai).
connected(mumbai,bangalore).
connected(bangalore,chennai).
connected(chennai,kolkata).
connected(kolkata,patna).

connected(A,B) :- connected(B,A), !.
