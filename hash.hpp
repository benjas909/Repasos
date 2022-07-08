#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <iostream>
#include <string>
#define MAX_LENGTH 128

using namespace std;

struct slot {
    int key;
    string value;

    slot();
};



#endif