#include <iostream>
#include <assert.h>
using namespace std;

typedef int tElemCola;

class tCola {
    private:
        int maxSize;
        int front;
        int rear;
        tElemCola* queueArray;
    public:
        tCola(int size = defaultSize) {
            maxSize = size + 1;
            rear = 0;
            front = 1;
            queueArray = new tElemCola[maxSize];
        }
        ~tCola() {
            delete [] queueArray;
        }
        void clear() {
            rear = 0;
            front = 1;
        }
        void enqueue(tElemCola item) {
            assert (((rear + 2) % maxSize) != front);
            rear = (rear + 1) % maxSize;
            queueArray[rear] = item;
        }
        int length() {
            return ((rear + maxSize) - front + 1) % maxSize;
        }
        tElemCola dequeue() {
            assert(length() != 0);
            tElemCola item = queueArray[front];
            front = (front + 1) % maxSize;
            return item;
        }
        tElemCola frontValue() {
            assert(length() != 0);
            return queueArray[front];
        }
        
}