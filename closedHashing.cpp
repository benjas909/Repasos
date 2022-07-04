#include <iostream>
using namespace std;


class hashDict {
    #define M 1000000
    #define EMPTY -1

    const int C, C1, C2, C3;


    typedef int keyType;

    struct infoType {
        string thing;
    };

    struct slot {
        keyType key;
        infoType info;
    };

    slot HT[M];

    int h (keyType k) {
        return k % M;
    }

    int h2(keyType k) {
        return k % M;
    }

    // Linear
    int p(keyType k, int i) {
        return i;
    }

    /* Constant Intervals
    int p(keyType k, int i) {
        return i * C;
    }

    Quadratic
    int p(keyType k, int i) {
        if (i == 0) return 0;
        return C1*i*i + C2*i + C3;
    }

    Double Hashing
    int p(keyType k, int i) {
        return i * h2(k);
    }*/


    int hashInsert (slot HT[], keyType k, infoType I) {
        int start, i;
        int pos = start = h(k);

        for (i = 1; HT[pos].key != EMPTY && HT[pos].key != k; i++) {
            pos = (start + p(k, i)) % M;    // next slot in the sequence.
        }

        if (HT[pos].key == k) {
            return 0;   // insertion failed: key is already in the table.
        }

        else {
            HT[pos].key = k;
            HT[pos].info = I;
            return 1;   // insertion successful.
        }
    }

    infoType hashSearch (slot HT[], keyType k) {
        int start, i;
        int pos = start = h(k);

        for (i = 1; HT[pos].key =! EMPTY && HT[pos].key =! k; i++) {
            pos = (start + p(k, i)) % M;
        }

        if (HT[pos].key == k) {
            return HT[pos].info;
        }

        else {
            return NULL;
        }
    }
}

int main() {

}