#include <iostream>
using namespace std;

typedef int keyType;

struct infoType {
        string thing;
    };

class hashDict {
    private:
        int M;
        int count;
        keyType EMPTYKEY;

        int h (keyType k) {
            return k % M;
        }

        int h2(keyType k) {
            return k % M;
        }


};