/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Appending a list to another list
 */

% Usage: app(List1, List2, CombinedList)

% If List1 is empty then just List2
app([],Y,Y).
% Head of List1 is Head of Combined List and
%   the rest is appending tail of List1 with List2
app([H|X],Y,[H|Z]) :- app(X,Y,Z).
