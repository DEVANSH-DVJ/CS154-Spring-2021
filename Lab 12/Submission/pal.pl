pal([]).
pal([_]).
pal(PAL) :-
  append([H|T], [H], PAL),
  pal(T).
