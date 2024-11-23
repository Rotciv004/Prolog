#include "list.h"
#include <iostream>

using namespace std;

PNod creare_rec() {
    TElem x;
    cout << "x= ";
    cin >> x;
    if (x == 0)
        return NULL;
    else {
        PNod p = new Nod();
        p->e = x;
        p->next = creare_rec();
        return p;
    }
}

List create() {
    List l;
    l._prim = creare_rec();
    return l;
}

void tipar_rec(PNod p) {
    if (p != NULL) {
        cout << p->e << " ";
        tipar_rec(p->next);
    }
}

void print(List l) {
    tipar_rec(l._prim);
}

void distrug_rec(PNod p) {
    if (p != NULL) {
        distrug_rec(p->next);
        delete p;
    }
}

void destroy(List l) {
    distrug_rec(l._prim);
}

int sumEvenSubtractOdd_rec(PNod p) {
    if (p == NULL)
        return 0;
    if (p->e % 2 == 0)
        return p->e + sumEvenSubtractOdd_rec(p->next);
    else
        return -p->e + sumEvenSubtractOdd_rec(p->next);
}

int sumEvenSubtractOdd(List l) {
    return sumEvenSubtractOdd_rec(l._prim);
}


bool isPresent_rec(PNod p, TElem elem) {
    if (p == NULL)
        return false;
    if (p->e == elem)
        return true;
    return isPresent_rec(p->next, elem);
}

void difference_rec(PNod p1, List l2, List& result) {
    if (p1 == NULL)
        return;


    if (!isPresent_rec(l2._prim, p1->e)) {
        PNod newNode = new Nod();
        newNode->e = p1->e;
        newNode->next = result._prim;
        result._prim = newNode;
    }
    difference_rec(p1->next, l2, result);
}

List difference(List l1, List l2) {
    List result;
    result._prim = NULL;
    difference_rec(l1._prim, l2, result);
    return result;
}
