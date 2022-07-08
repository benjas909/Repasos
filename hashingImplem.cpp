#include <iostream>
#include <hash.hpp>
using namespace std;

#define M 1000000
#define EMPTY '\0'

typedef int keyType;

typedef string infoType;

class hashDict {
    private:
        slot *H;
        int count, C;

    public:
        hashDict();

        ~hashDict(){;};

        int h (keyType k);

        int h2(keyType k);

        int p(keyType k, int i);

        int hashInsert (keyType k, infoType I);

        infoType hashSearch (keyType k);
};

hashDict::hashDict() {
    H = new slot[MAX_LENGTH];
    count = 0;
    C = 9;
}

int hashDict::h(keyType k) {
    return k % M;
}

int hashDict::h2(keyType k){
    return k % M;
}

int hashDict::p(keyType k, int i) {
    return i * C;
}

int hashDict::hashInsert (keyType k, infoType I) {
    int start, i;
    int pos = start = h(k);

    for (i = 1; H[pos].key != EMPTY && H[pos].key != k; i++) {
        pos = (start + p(k, i)) % M;    // next slot in the sequence.
    }

    if (H[pos].key == k) {
        return 0;   // insertion failed: key is already in the table.
    }

    else {
        H[pos].key = k;
        H[pos].value = I;
        return 1;   // insertion successful.
    }
}

infoType hashDict::hashSearch (keyType k) {
    int start, i;
    int pos = start = h(k);

    for (i = 1; H[pos].key != EMPTY && H[pos].key != k; i++) {
        pos = (start + p(k, i)) % M;
    }

    if (H[pos].key == k) {
        return H[pos].value;
    }

    else {
        return "-1";
    }
}


int main(){
    hashDict hashtable;
    hashtable.hashInsert(3, "Peru");
    cout << "buenas";
    // cout << hashtable.hashSearch(3) << "hola";
    return 0;
}