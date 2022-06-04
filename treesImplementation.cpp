#include <iostream>
using namespace std;

typedef int tipoElem;

struct treeNode {
    tipoElem info;
    treeNode* hijoIzq;
    treeNode* hermDer;
};

struct tNodoArbolBin {
    tipoElem info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

// Funciones auxiliares

int procesar(tipoElem info){
    cout << info << endl;
}

void clearHelp(tNodoArbolBin* nodo) {
    if (nodo == NULL) return;
    clearHelp(nodo->izq);
    clearHelp(nodo->der);
    delete nodo;
}

void inOrdenHelp(tNodoArbolBin* nodo) {
    if (nodo == NULL) return;
    inOrdenHelp(nodo->izq);
    procesar(nodo->info);
    inOrdenHelp(nodo->der);
}

void preOrdenHelp(tNodoArbolBin* nodo) {
    if (nodo == NULL) return;
    procesar(nodo->info);
    preOrdenHelp(nodo->izq);
    preOrdenHelp(nodo->der);
}

void postOrdenHelp(tNodoArbolBin* nodo) {
    if (nodo == NULL) return;
    postOrdenHelp(nodo->izq);
    postOrdenHelp(nodo->der);
    procesar(nodo->info);
}

int findHelp(tNodoArbolBin* nodo, tipoElem item) {
    if (nodo == NULL) return 0;
    if (nodo->info == item) return 1;
    if (item < nodo->info) {
        return findHelp(nodo->izq, item);
    }
    else {
        return findHelp(nodo->der, item);
    }
}

// Fin de funciones auxiliares

class arbolBin {
    tNodoArbolBin* raiz;
    int nElems;
};

class tABB {
    tNodoArbolBin* raiz;
    int nElems;
    public:
        tABB() {
            raiz = NULL;
            nElems = 0;
        }
        void clear() {
            clearHelp(raiz);
            raiz = NULL;
            nElems = 0;
        }
        void inOrden() {
            inOrdenHelp(raiz);
        }
        void preOrden() {
            preOrdenHelp(raiz);
        }
        void postOrden() {
            postOrdenHelp(raiz);
        }
        int find(tipoElem item) {
            return findHelp(raiz, item);
        }
}