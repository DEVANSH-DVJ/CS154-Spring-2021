/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Check if it is substring
 */

% Basic Usage: sub(+SubList, +List)
sub(X,S) :- append(_,T,S), append(X,_,T), X \= [].
