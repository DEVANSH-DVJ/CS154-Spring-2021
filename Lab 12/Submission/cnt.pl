/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Counting occurance of an element in a list
 */

% Basic Usage: cnt(+List, +Element, -Count)
cnt([],_,0).
cnt([X|T],X,Y) :- cnt(T,X,Z), Y is Z+1.
cnt([X1|T],X,Z) :- cnt(T,X,Z), X1 \= X.
