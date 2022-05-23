#include <iostream>
using namespace std;

class Car {
    private:
        //ADT data, not visible to the user
        int currentSpeed;
        float fuelQuantity;
        bool engineOn;
        int currentGear;
    public:
        //ADT operations, visible and usable by the user
        Car() {
            engineOn = false; currentSpeed = 0; fuelQuantity = 0.0; currentGear = 0;
        };  // Class constructor (*)
        Car(float fQ) {
            engineOn = false; currentSpeed = 0; fuelQuantity = fQ; currentGear = 0;
        };  // A class constructor can also have parameters
        ~Car() {;}; // Class destructor (**)
        void turnOn() {
            engineOn = true;
            currentSpeed = 0;
        };
        void accelerate() {
            currentSpeed++;
            fuelQuantity--;
        };
        void brake() {
            currentSpeed--;
        };
        bool hasFuel() {
            return fuelQuantity > 0.0;
        };
        void refuel(float quantity) {
            fuelQuantity += quantity;
        };
        void upShift() {
            currentGear++;
        };
        void downShift() {
            currentGear--;
        };
        void neutral() {
            currentGear = 0;
        };
        //These functions are the only ones that can modify the values of the ADT
};

int main(){
    Car shitbox;
    // At this point, shitbox.engineOn == false, shitbox.currentSpeed == 0, shitbox.fuelQuantity == 0.0 and shitbox.currentGear = 0.
    shitbox.turnOn();
    shitbox.refuel(50.0);
    while (shitbox.hasFuel()) {
        shitbox.accelerate();
        /* ... */
    }
    Car AE86(25.0);
    // A new car has been created and it is loaded with 25 liters of fuel
    return 0;
}

/* 
(*) Constructor: They allow us to automatically initialize the variables of a class when 
declaring it. The declaration of a class automatically calls the constructor.
(**) Destructor: The opposite of a constructor, it is used to free the memory requested by the class (if that's the case), close
files open by the class, etc. In this example it is not necessary, because we didn't request memory nor did we open a file, and the variables
of a class self destruct at the end of its use. A class can have only one destructor and it never has parameters. 
*/