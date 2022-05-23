#include <iostream>
#include <string>
using namespace std;

struct Student{
    int carreerCode;
    int startYear;
    string name;
    string lastName;
    float lastAverage;
};

//ejemplo del apunte: Struct que almacena 1000 alumnos, y para cada uno de ellos se guarda su rol, su fecha de nacimiento y la lista
//de cursos que ha tomado y la cantidad de estos.
struct {
    int rol;
    struct {
        int dia;
        int mes;
        int ano;
    } nacimiento;
    struct {
        int sigla;
        int nota;
    } cursos [50];
    int tomados;
} bd_alumnos[1000];

int main(){
    //assigning values to each field of the Student struct
    Student someGuy;
    someGuy.carreerCode = 735;
    someGuy.startYear = 2021;
    someGuy.name = "Benjamin";
    someGuy.lastName = "Aguilera";
    someGuy.lastAverage = 74.5;

    //It can also be done this way
    Student someOtherGuy = {735, 2020, "Quandale", "Dingle", 89.7};

    //We can also combine them with arrays, allowing us to have arrays of structs
    Student someGuys[4];
    someGuys[0].carreerCode = 736;
    someGuys[1].lastAverage = 73;
    someGuys[1].lastName = "Marrano";
    someGuys[3].startYear = 2022;

    //structs can also store arrays
    struct Example{
        int coords[4];
        string something;
    };

    Example ween;
    ween.coords[0] = 52;
    ween.coords[1] = 33;
    ween.coords[2] = 44;
    ween.something = "Greetings planet";

    return 0;
}