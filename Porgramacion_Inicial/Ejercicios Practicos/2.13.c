/*
Confeccionar un programa que solicite el ingreso de un número entero positivo de 
4 cifras y pueda calcular e informar la suma de sus dígitos hasta llegar a una
 sola cifra. Ej:2561 → 5.
*/

#include <stdio.h>

int main ()
{
    int num, dig1,dig2,dig3,dig4, suma;
    printf("\nIngrese un numero entero positivo de 4 cifras: ");
    scanf(" %d", &num);

    dig1 = num / 1000;
    dig2 = (num % 1000) / 100;
    dig3 = (num % 100) / 10;
    dig4 = num % 10;

    suma = dig1 + dig2 + dig3 + dig4;
    
}