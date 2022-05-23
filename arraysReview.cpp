#include <iostream>
#include <string>
using namespace std;

int main(){

    //declaring a list of integers and assigning values
    int tinylist[] = {1, 3, 4 ,2};

    //accessing and printing a value from the list
    cout << tinylist[1] << endl;

    //modifying a value from the list
    tinylist[1] = 6;
    cout << tinylist[1] << endl;
    
    //looping through the elements of a list
    for (int i = 0; i < 4; i++){
        cout << tinylist[i] << endl;
    }

    //a list can also be declared without specifying the number of elements
    string names[] = {"Benja", "Bingus"};
    //but it will only reserve space for the number of elements assigned in its declaration, in this case, 2

    //you can also declare a list without assigning any values initially, reserving the spaces in memory to assign later
    int nums[4];
    nums[0] = 4;
    nums[1] = 3;
    //the spaces without value are reserved for later
    return 0;
}