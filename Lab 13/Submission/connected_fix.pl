connected(delhi,mumbai).
connected(mumbai,bangalore).
connected(bangalore,chennai).
connected(chennai,kolkata).
connected(kolkata,patna).

isconnected(A,B) :- connected(A,B); connected(B,A).
