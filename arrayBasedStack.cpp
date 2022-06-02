#include <iostream>
#include <assert.h>
using namespace std;

typedef int tElemPila;

class tPila {
    unsigned int maxSize;   // Maximum size of the stack
    unsigned int top;   // Current size of the stack
    tElemPila* stackArray;  // Array with the elements of the stack
    public:
        tPila(int maxsize) {
            maxSize = maxsize;
            top = 0;
            stackArray = new tElemPila[maxSize];
        }
        // Inserts an array at the top of the stack
        int push(tElemPila item) {
            if (top == maxSize) {
                return 0;
            }
            stackArray[top++] = item;
            return 1;   // Inserted successfully 
        }
        // Pops (deletes) the value at the top of the stack
        void pop() {
            if (top == 0) {
                return;   // Can't pop, the stack is empty
            }
            top--;
        }
        // Returns the value at the top of the stack
        tElemPila topValue() {
            assert(top != 0);
            return stackArray[top - 1];
        }
        int size() const {
            return top;
        }
        void clear() {
            top = 0;
        }
};

int main() {
    tPila test_listita(999);
    int i;
    tElemPila cosa;
    cout << "Número de elementos: ";
    cin >> i;
    for (int j = 0; j < i; j++) {
        cout << "A insertar: ";
        cin >> cosa;
        test_listita.push(cosa);
    }
    int l = test_listita.size();
    cout << "el tamaño de la pila es " << l << endl;
    for (int j = 0; j < l; j++) {
        cout << test_listita.topValue() << endl;
        test_listita.pop();
    }
    return 0;
}