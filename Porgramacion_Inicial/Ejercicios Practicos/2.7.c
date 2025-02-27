/*
2.7. Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.
*/

#include <stdio.h>

int main ()
{
    int numero, unidad, decena, centena;

    printf("\nIngrese un numero entero de 3 cifras: ");
    scanf(" %d", &numero);

    unidad = numero % 10; //mostrara el resto de la division
    decena = (numero / 10) % 10;  // operaciones multiples
    centena = numero / 100; //mostrara la division
    
    printf("\nEl numero en unidades es: %d", unidad);
    printf("\nEl numero en decenas es: %d", decena);
    printf("\nEl numero en centenas es: %d", centena);

    system("pause");
    return 0;
}