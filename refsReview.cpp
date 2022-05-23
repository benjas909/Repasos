#include <iostream>
#include <string>
using namespace std;

int main(){
    //a reference variable is like a nickname for another variable
    string food = "Completo";
    string &yum = food; //now we can refer to the first variable either as "food" or "yum"

    cout << food << endl;
    cout << yum << endl; //outputs whatever is in the variable food

    //the & operator can also be used to get the memory address of a variable
    cout << &food << endl; //outputs the memory address of food

    return 0;

}