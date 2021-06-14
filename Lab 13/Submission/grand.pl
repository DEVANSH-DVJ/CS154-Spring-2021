child(sally,tom).
child(uma,sally).
child(rama,dasharath).
child(lava,rama).
child(kusha,rama).
child(arjuna,pandu).
child(pandu,vichitravirya).
child(vichitravirya,shantanu).
child(abhimanyu,arjuna).
child(parikshit,abhimanyu).
child(janmejay,parikshit).
wife(subhadra,arjuna).
wife(utttara,abhimanyu).
wife(kunti,pandu).
wife(ambalika,vichitravirya).
wife(satyavati,shantanu).
wife(iravati,parikshit).

grandchild(X,Y) :- child(X,Z), child(Z,Y).
grandparent(X,Y) :- grandchild(Y,X).
grandmother(X,Y) :- grandparent(Z,Y), wife(X,Z).
granddaughter(X,Y) :- grandparent(Y,Z), wife(X,Z).
