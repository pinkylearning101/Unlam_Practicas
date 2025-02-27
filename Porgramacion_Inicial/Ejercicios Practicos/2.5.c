/*
2.5. Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el 
50% son tarros de 1Lt, el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de 
1Lt., 4Lts. Y 20 Lt
*/

#include <stdio.h>

int main ()
{
    int tarros, tarros1, tarros4, tarros20;

    printf("\nIngrese la cantidad de tarros de pintura: ");
    scanf(" %d", &tarros);

    /*
    Maneras de resolverlo: multiplicacion o division
    Es mas facil por multiplicacion pero tambien la otra
    manera de hacerlo se ve asi:

    tarros1 = tarros / 2; // 50% de los tarros
    tarros4 = tarros * 3 / 10; // 30% de los tarros
    tarros20 = tarros - (tarros1 + tarros4); // El resto de los tarros
    */

    // <--- Mas practica aca
    tarros1 = tarros * 0.5; // 50% de los tarros
    tarros4 = tarros * 0.3; // 30% de los tarros
    tarros20 = tarros - (tarros1 + tarros4); // El resto de los tarros

    printf("\nLa cantidad de tarros de 1Lt es de %d", tarros1);
    printf("\nLa cantidad de tarros de 4Lt es de %d", tarros4);
    printf("\nLa cantidad de tarros de 20Lt es de %d", tarros20);

    system("pause");
    return 0;
}