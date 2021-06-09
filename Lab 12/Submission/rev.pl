/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Reversing a list
 */

% Usage: rev(List, ReversedList)

% Reversal of an empty list is itself.
rev([],[]).
% Reverse the tail and append the head at the end
rev([H|T],R) :- rev(T,Tr), append(Tr,[H],R).
