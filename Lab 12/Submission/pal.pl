/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Check if a string is a palindrome
 */

% Usage: pal(List)

% Empty list is a palindrome
pal([]).
% Singleton list is a palindrome
pal([_]).
% List is a palindrome if
%   first and last elements are equal and
%   the remaining portion is also a palindrome
pal(P) :- append([H|T],[H],P), pal(T).
