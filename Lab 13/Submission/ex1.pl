human(aba).
human(baba).
human(caca).
human(nana).
hascommonsense(baba).
hascommonsense(caca).

wise(X) :- human(X), hascommonsense(X).
