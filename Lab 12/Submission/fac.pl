/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Computing factorial
 */

% Usage: fac(Number, Factorial)

% 0! = 1
fac(0,1).
% N! = N * (N-1)!
fac(N,NF) :- N1 is N-1, fac(N1,N1F), NF is N1F * N.
