#include <iostream>
using namespace std;

//Functions that return arrays
//This is achieved dynamically assigning memory for an array inside the function and returning a pointer to its base address
//The return type must be a pointer to the base type of the returned array
struct dot{
    float x;
    float y;
};

dot* f(int n){
    dot* p = new dot[n];
    //... Reading and proccessing the dots some way
    return p;
}   //This example function receives an int "n" as a parameter, and returns a pointer to an array of n integers
    //An example of a call to this function is the following

int main(){
    int i;
    dot* q;
    // ...
    q = f(100); //At this point we know that q is a dynamic array of 100 integers
    
    for(i = 0; i < 100; i++){
        cout << "Something";
        //Does something with the dot q[i]
    }
    delete [] q; //The array memory must be freed when it is no longer necessary
        return 0;
}
    /*
    However, the size of the returned array is not always known. In this case, the function must also inform the size of the array
    it will return. Otherwise, the caller of the function and receiver of the array won't know the size of it, and thus, it will not be able
    to process it. A simple way of informing the size of the array is by adding a parameter, which is passed by reference.
    Example: filter function, it receives a float array and a float value c. It must return an array with all the elements of the original
        array with a value smaller than c
    */
float* filter(float a[], int n, float c, int& m){
    int i;
    // First, it sounts the elements of the array it will return
    for (m = i = 0; i < n; i++)
        if (a[i] < c) m++;
    
    float* p = new float[m];
    int j;

    for (j = i = 0; i < n; i++)
        if (a[i] < c) {
            p[j] = a[i];
            j++;
        }
    return p;
    /*
    n is the size of the array a, and m is a parameter passed by reference in which the function will inform the size of the array to be
    returned
    */
}
// An example of a call to this function is the following
int main2(){
    int m;
    float a[10] = {3.2, 6.9, 2.1, 7.3, 9.3, 8.5, 3.9, 5.3, 7.5, 9.9};
    float* q;
    // ...
    q = filter(a, 10, 5.0, m);
    // At this point we know that the array q has size m (it is modified inside the function)
    for (int i = 0; i < m; i++) 
        cout << q[i] << endl;
    // ...
    delete [] q;
    return 0;
}
    

