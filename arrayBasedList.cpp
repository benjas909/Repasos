#include <iostream>
using namespace std;

typedef int tElemLista;

class tLista {
    unsigned int maxSize;
    unsigned int listSize;
    unsigned int curr;
    tElemLista* listArray;
public:
    tLista() {
        maxSize = 8000;
        listSize = 0;
        curr = 0;
        listArray = new tElemLista[maxSize];
    }
    ~tLista(){
        delete[] listArray;
    }
    void clear() {
        listSize = curr = 0;
    }
    int insert(tElemLista item) {
        int i;
        if (listSize >= maxSize) {
            return -1;
            }
        for (i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];
            }
        listArray[i] = item;
        listSize++;
        return i;
    }
    int append(tElemLista item) {
        if (listSize >= maxSize) {
            return 0;
        }
        listArray[listSize++] = item;
        return 1;
    }
    tElemLista erase() {
        tElemLista item;
        int i;
        if (curr > 0 || curr >= listSize) {
            return -1;
        }
        item = listArray[curr];
        for (i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return item;
    }
    void moveToStart() {
        curr = 0;
    }
    void moveToEnd() {
        curr = listSize;
    }
    void prev() {
        if (curr != 0) {
            curr--;
        }
    }
    void tLista() {
        if (curr < listSize){
            curr++;
        }
    }
    int length() {
        return listSize;
    }
    int currPos(){
        return curr;
    }
    void moveToPos(int i) {
        curr = i;
    }
    tElemLista getValue() {
        return listArray[curr];
    }
    
};