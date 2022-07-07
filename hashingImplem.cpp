#include <iostream>
using namespace std;

#define M 1000000
#define EMPTY '\0'

typedef int keyType;

typedef string infoType;
    
struct slot {
    keyType key;
    infoType info;
};


class hashDict {
    private:
        slot HT[M];
        int count, C;
        keyType EMPTYKEY;
        infoType EMPTYSLOT;

        int h (keyType k) {
            return k % M;
        }

        int h2(keyType k) {
            return k % M;
        }

        int p(keyType k, int i) {
        return i * C;
    }

        
    public:
        hashDict() {
            count = 0;
            C = 9;
        }
        ~hashDict(){;};

        int hashInsert (keyType k, infoType I) {
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

        infoType hashSearch (keyType k) {
            int start, i;
            int pos = start = h(k);

            for (i = 1; HT[pos].key != EMPTY && HT[pos].key != k; i++) {
                pos = (start + p(k, i)) % M;
            }

            if (HT[pos].key == k) {
                return HT[pos].info;
            }

            else {
                return "-1";
            }
        }



};

int main(){
    hashDict hashtable;
    hashtable.hashInsert(3, "Peru");
    cout << "buenas";
    // cout << hashtable.hashSearch(3) << "hola";
    return 0;
}