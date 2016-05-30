/*

    Zelda Return of the Hylian

    Copyright (C) 2005-2008  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#include "Listable.h"
#include "3ds/gfx_3ds.h" //cancellare


Listable::Listable() : suivant(0), id(0) {
}

Listable::~Listable() {
	if(suivant) delete suivant;
	suivant = 0;
}

int Listable::size() {
    if (suivant == 0) return 0;
    return (suivant->size() + 1);
}
        
void Listable::ajout(Listable* l) {
    if (suivant == 0) {
        suivant = l;
        suivant->id = id + 1;
        delete suivant->suivant; // au cas o� on a donn� une liste au lieu d'un �l�ment
    }
    else suivant->ajout(l);
}

void Listable::enleve(Listable* l) {
    if (suivant == 0) return;
    if (l == suivant) {
        Listable* tmp = suivant->suivant;
        suivant->suivant = 0; //pour �viter suppressions r�cursives
        delete suivant;
        suivant = tmp;
    }
    else suivant->enleve(l);
}

bool Listable::operator==(const Listable* l) {
    return (id == l->id);
}

int Listable::getListId() {return id;}
