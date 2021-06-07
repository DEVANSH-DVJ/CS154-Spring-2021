/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Appending a list to another list
 */

% Basic Usage: app(+List1, +List2, -CombinedList)
app([],Y,Y).
app([H|X],Y,[H|Z]) :- app(X,Y,Z).
