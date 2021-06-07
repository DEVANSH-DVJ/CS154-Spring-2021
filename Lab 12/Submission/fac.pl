/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Computing factorial
 */

% Basic Usage: fac(+Number, -Factorial)
fac(0,1).
fac(N,NF) :- N1 is N-1, fac(N1,N1F), NF is N1F * N.
