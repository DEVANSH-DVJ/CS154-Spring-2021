/**
 * Author: Devansh Jain (190100044)
 * Lab 12 - Counting occurance of an element in a list
 */

% Usage: cnt(List, Element, Count)

% For empty list, every element has count 0
cnt([],_,0).
% If the head of list is the desired element then
%   count is 1 + count in tail of list
cnt([X|T],X,Y) :- cnt(T,X,Z), Y is Z+1.
% If the head of list is not the desired element then
%   count is count in tail of list
cnt([X1|T],X,Z) :- cnt(T,X,Z), X1 \= X.
