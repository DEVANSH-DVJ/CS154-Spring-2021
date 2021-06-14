last([A|[]],A).
last([A|L],E) :- last(L,E).
reverse([A|L],[E|U]) :- last(L,E), reverse(L,U).
