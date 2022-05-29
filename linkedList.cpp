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
        void erase() {
            tNodo* aux = curr->sig;
            curr->sig = curr->sig->sig;
            delete aux;
        }
        void moveToStart() {
            curr = head;
            pos = 0;
        }
        void moveToEnd() {
            curr = tail;
            pos = listSize;
        }
        void prev() {
            tNodo* temp;
            if (curr == head) {
                return;
            }
            temp = head;
            while (temp->sig != curr) {
                temp = temp->sig; 
            }
            curr = temp;
            pos--;
        }
        void next() {
            if (curr != tail) {
                curr = curr->sig;
                pos++;
            }
        }
        void moveToPos(unsigned int posicion){
            unsigned int i;
            if (posicion < 0 || posicion > listSize) {
                return;
            }
            curr = head;
            pos = 0;
            for (i = 0; i < posicion; i++) {
                curr = curr->sig;
                pos++;
            }
        }


};