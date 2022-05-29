#include <iostream>
using namespace std;

typedef int tElemLista;

struct tNodo {
    tElemLista info;
    tNodo* sig;
};

class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;
        unsigned int listSize;
        unsigned int pos;
    public:
        tLista() {
            head = tail = curr = new tNodo;
            listSize = 0;
            pos = 0;
        }
        void clear() {

        }
        int insert(tElemLista item) {
            tNodo* aux = curr->sig;
            curr->sig = new tNodo;
            curr->sig->info = item;
            curr->sig->sig = aux;
            if (curr == tail) {
                tail = curr->sig;
            }
            listSize++;
            return pos;
        }


};