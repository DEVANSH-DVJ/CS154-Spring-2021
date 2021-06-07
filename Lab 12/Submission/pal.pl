pal([]).
pal([_]).
pal(P) :- append([H|T],[H],P), pal(T).
