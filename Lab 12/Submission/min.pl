/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Finding minimum in a list
 */

% Basic Usage: min(+List, -MinimumElement)
min([X],X).
min([H,K|T],M) :- min([H|T],M), H =< K.
min([H,K|T],M) :- min([K|T],M), H > K.
