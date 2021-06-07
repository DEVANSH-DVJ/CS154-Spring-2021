/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Reversing a list
 */

% Basic Usage: rev(+List, -ReversedList)
rev([],[]).
rev([H|T],R) :- rev(T,Tr), append(Tr,[H],R).
