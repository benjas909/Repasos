#include <iostream>
#include <string>
using namespace std;

int main(){

    //declaring an array of integers and assigning values
    int tinyarray[] = {1, 3, 4 ,2};

    //accessing and printing a value from the array
    cout << tinyarray[1] << endl;

    //modifying a value from the array
    tinyarray[1] = 6;
    cout << tinyarray[1] << endl;
    
    //looping through the elements of an array
    for (int i = 0; i < 4; i++){
        cout << tinyarray[i] << endl;
    }

    //an array can also be declared without specifying the number of elements
    string names[] = {"Benja", "Bingus"};
    //but it will only reserve space for the number of elements assigned in its declaration, in this case, 2

    //you can also declare an array without assigning any values initially, reserving the spaces in memory to assign later
    int nums[4];
    nums[0] = 4;
    nums[1] = 3;
    //the spaces without value are reserved for later
    return 0;
}