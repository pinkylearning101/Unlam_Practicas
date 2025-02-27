/*
Una  pizzería  vende  empanadas  por  unidad  o  por  docena,  la  docena
ccuesta  $300  pero  si  se  compra individualmente se cobra $30 la unidad.
Si se compran más empanadas que no se agrupen en docenas las 
adicionales se cobran como por unidad. Indicar el precio total a abonar
*/

#include <stdio.h>

int main ()
{
    int empanadas, docenas, individuales;
    float precio;

    printf("\nIngrese la cantidad de empanadas a comprar: ");
    scanf(" %d", &empanadas);

    docenas = empanadas / 12;
    individuales = empanadas % 12;
    precio = (docenas * 300) + (individuales * 30);

    printf("\nEl precio total a abonar es de %.2f", precio);

    system("pause");
    return 0;
}