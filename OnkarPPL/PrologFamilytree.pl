male(sachin).
male(mihir).
male(parimal).
female(anne).
female(hannah).
female(ellie).
parent_of(sachin,mihir).
parent_of(sachin,hannah).
parent_of(anne,mihir).
parent_of(hannah,ellie).

father_of(X,Y):-male(X),parent_of(X,Y).
mother_of(X,Y):-female(X),parent_of(X,Y).
sister_of(X,Y):-female(X),father_of(F,X),father_of(F,Y).
sister_of(X,Y):-female(X),mother_of(F,X),mother_of(F,Y).
grandfather_of(X,Y):-male(X),parent_of(X,Z),parent_of(Z,Y).
