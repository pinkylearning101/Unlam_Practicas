/*
2.1. Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo.
*/
#include <stdio.h>

int main (){

    int horas,valor,sueldo;

    printf("\nIngrese la cantidad de horas trabajadas: ");
    scanf( " %d", &horas);

    printf("\nIngrese el valor por hora: ");
    scanf(" %f", &valor);

    sueldo = horas * valor;

    printf("\nEl sueldo del empleado es: %d", sueldo);
    system("pause");
    return 0;
}