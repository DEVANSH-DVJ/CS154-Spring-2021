/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Check if it is substring
 */

% Usage: sub(SubList, List)

% X is a substring if
%   X isn't empty and
%   there is a prefix of S, say T, whose suffix is X
sub(X,S) :- append(_,T,S), append(X,_,T), X \= [].
