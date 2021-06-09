/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Finding minimum in a list
 */

% Usage: min(List, MinimumElement)

% Minimum of a singleton list is the element itself
min([X],X).
% If the first element is less than second element then
%   remove the second element
min([H,K|T],M) :- min([H|T],M), H =< K.
% If the first element is more than second element then
%   remove the first element
min([H,K|T],M) :- min([K|T],M), H > K.
