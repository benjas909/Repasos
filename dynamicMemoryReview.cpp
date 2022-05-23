#include <iostream>
using namespace std;

int main(){
    /*
    In many cases, we don't know how much memory our program will need during its runtime, and it will depend on many factors, like 
    the size of the input data. One of the many issues with these cases is that we can't declare an array as we know now.
    The solution to this problem is dynamic memory allocation, which allows us to request and free arbitrary quantities of memory
    at any point during a program's runtime.
    In C++ we request memory from the heap, which is like a warehouse of memory, and we request and free memory using the new and delete 
    operations, respectively.
    */
    int n, i;
    int* p;

    cout << "Data quantity: ";
    cin >> n;

    p = new int[n]; //We request memory for an array of n integers

    for (i = 0; i < n; i++){
        cout << "Number to be inserted in position " << i + 1 << "/" << n << ": ";
        cin >> p[i];
    }
    /*...
    array processing
    */
    delete [] p; //Frees the requested memory space, must be done by the programmer

    //----------------------------------------------------------------------------
    /*
    The 'new' operator
    we use it to request memory from the heap, it returns a pointer to the assigned memory
    */
    int* r;
    r = new int; //Requests memory for an integer, r is now pointing to the given memory block
    //We can do everything we learned about pointers to this one.
    *r = 5;
    //The memory space given by the heap has not been declared, and does not have a name, the only way to access it is by pointers

    //We can initialize dynamic memory this way, assigning the value to the memory block inmediately
    int* s = new int(25);
    float* q = new float(16.5);

    /*
    Dynamic allocation of arrays
    This is very useful when we don't know exactly the size an array will have when running the program
    In this example we request memory for an array of 10 integers and the pointer t now points to the first element of the array
    */
    int* t = new int[10]; //The size can be a variable
    //we can use the pointer to manipulate the array
    p[4] = 9;
    //If the memory given is not enough for the program we get a bad alloc error
    
    //-------------------------------------------
    /*
    The 'delete' operator
    In C++, dynamic memory is managed entirely by the programmer, so it's their responsability to return the memory requested to the heap,
    for this we use the 'delete' operator
    */
    delete r;
    delete s;
    delete q;
    delete [] t;
    //Every use of new, must have its delete
    return 0;
}