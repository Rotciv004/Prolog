#pragma once
#ifndef LISTA_H
#define LISTA_H


typedef int TElem;

struct Nod;

typedef Nod* PNod;

typedef struct Nod {
    TElem e;
    PNod next;
};

typedef struct {
    PNod _prim;
} List;

List create();

void print(List l);

void destroy(List l);



int sumEvenSubtractOdd(List l);

List difference(List l1, List l2);

#endif
