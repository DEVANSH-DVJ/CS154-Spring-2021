/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Check if a string is a palindrome
 */

% Basic Usage: pal(+List)
pal([]).
pal([_]).
pal(P) :- append([H|T],[H],P), pal(T).
