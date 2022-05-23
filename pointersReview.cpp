#include <iostream>
#include <cstdio>
using namespace std;



int main(){
    //a pointer is a variable that stores a memory address
    string food = "cookie";
    string* ptr = &food; //the memory address of the food variable is assigned to the pointer, the type of the pointer has to match the 
                        //type of the variable that it is pointing to

    cout << food << endl; //outputs the value of food
    cout << &food << endl; //outputs the memory address of food
    cout << ptr << endl; //outputs the value of the pointer, which is the memory address of food
    //these last two lines output the same thing

    //we can also get the value that is in the memory address being pointed at
    cout << *ptr << endl; // the * operator is known as the dereference operator

    //NOTE: the * operator has two functions depending on where it's used:
        //if it's used in a declaration, it creates a pointer (line 7)
        //if it's not, it serves as the dereference operator (line 16)

    //using the dereference value, we can also modify the original value
    *ptr = "bread";
    cout << food << endl;
    
    //There is a special pointer that doesn't point to anything
    int* pointy = NULL;
    //It's commonly used to indicate the end of a data structure

    //POINTERS AND ARRAYS
    //We can have pointers to elements in an array
    int a[5] = {7, 4, 9, 11, 8};
    int* p = &a[0];
    /*Obs: the name of an array in C++ acts kinda like a pointer to the first element of it, and knowing that all the elements of
    an array are stored together in consecutive memory blocks, we can access the whole array using its name and increasing the value of
    the pointer.
    This means: (p = &a[0]) == (p = a)
    */

    int x;
    p = a;
    x = a[3];
    cout << x << endl; //prints 11
    x = *(p + 3);
    cout << x << endl; //prints 11
    x = p[3];
    cout << x << endl; //prints 11
    
    //We can also point to structs, for example
    struct punto{
    float x;
    float y;
    };
    punto s = {4.2, 3.6};
    punto* poi;
    poi = &s; //in the case of structs, it is necessary to use the & operator

    //to access and modify a field in the structure, we can do
    (*poi).x = 2.5; //in this case, the parenthesis are mandatory, because the . operator has preference over the * operator
    //a simpler way to do this is by using the -> operator
    poi->x = 2.5;

    //cool trick to initialize an array of structs using pointers
    punto arr[4];
    punto* pointer;
    for (pointer = arr; pointer <= &arr[3]; pointer++){
        pointer->x = 0;
        pointer->y = 0;
    }//given that this is an array of structs, we can assign the name of the array to the pointer and it will point to the first element
    //and keep adding to it to make it advance in the array

    //VOID POINTERS
    //They allow us to create pointers that can point to any type
    int i;
    float f[5];
    
    void *r, *k;
    r = (void*) &i;
    k = (void*) &f[3]; //we must use the cast operator to convert the types before assigning them, that way both sides are the same type
    //NOTE: we can't add integers to this type of pointer, because we don't know the type that will be pointed, so we don't know the number of bytes it needs
    
    return 0;
}
