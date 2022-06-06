#include <iostream>
using namespace std;

typedef int tElemLista;

struct tNodo {
    tElemLista info;
    tNodo* sig;
    tNodo* ant;
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
            head = curr = new tNodo;
            tail = new tNodo;
            head->sig = tail;
            tail->ant = head;
            listSize = 0;
            pos = 0;
        }
        void clear() {
            tNodo* ptrh = head;
            tNodo* ptrt = tail;
            tNodo* temp1;
            tNodo* temp2;
            while(listSize > 0) {
                cout <<  "largo " << listSize << endl;

                if (listSize == 1) {
                    delete ptrh; listSize--;
                    break;
                }

                temp1 = ptrh->sig;
                temp2 = ptrt->ant;
                
                delete ptrh; listSize--;
                delete ptrt; listSize--;
                ptrh = temp1;
                ptrt = temp2;
            }
            cout <<  "largo " << listSize << endl;
        }
        
        // int insertFront(tElemLista item) {
        //     tNodo* newNode = new tNodo;
        //     newNode->info = item;
        //     newNode->sig = head;
        //     newNode->ant = NULL;

        //     if(head != NULL)
        //         head->ant = newNode;

        //     head = newNode; 
            

        // }

        int insert(tElemLista item) {
            tNodo* aux = curr->sig;
            curr->sig = curr->sig->ant = new tNodo;
            curr->sig->info = item;
            curr->sig->sig = aux;
            curr->sig->ant = curr;
            if (curr == tail) {
                tail = curr->sig;
            }
            listSize++;
            return pos;
        }
        void erase() {
            tNodo* aux = curr->sig;
            curr->sig = curr->sig->sig;
            curr->sig->ant = curr;
            delete aux;
            listSize--;
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
                curr = curr->ant;
            }
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
        void printItem(){
            if (curr == NULL && head == NULL && tail == NULL) cout << "lista vacía";
            cout << curr->info;
        }
        int length() {
            return listSize;
        }
        void append(tElemLista item){
            tNodo* aux = tail->ant;
            tNodo* aux2 = tail->ant->sig;
            tail->ant = tail->ant->sig = new tNodo;
            tail->ant->info = item;
            tail->ant->ant = aux;
            tail->ant->sig = aux2;
        }


};

int main() {
    tLista test_list;
    tElemLista cosa;
    int i, wea;
    cout << "cantidad de cosas: "; 
    cin >> i;

    for (int j = 0; j < i; j++) {
        cout << "cosa a insertar: ";
        cin >> wea;
        test_list.append(wea);
    }
    test_list.moveToStart();
    for (int k = 0; k < i; k++){
        test_list.next();
        test_list.printItem();
        cout << "\n";
    }
    test_list.clear();
    test_list.moveToStart();
    cout << test_list.length();
    // test_list.printItem();



    return 0;
}