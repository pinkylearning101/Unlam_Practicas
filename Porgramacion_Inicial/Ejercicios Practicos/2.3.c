/*
2.3. Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes
aclaratorios la suma, el producto, el cociente y el resto.
*/

#include <stdio.h>

int main ()
{
    int num1,num2,suma,producto,cociente,resto;

    printf("\nIngrese el primer numero: ");
    scanf(" %d", &num1);

    printf("\nIngrese el segundo numero: ");
    scanf(" %d", &num2);

    suma = num1 + num2;
    producto = num1 * num2;
    cociente = num1 / num2;
    resto = num1 % num2;

    printf("\nLa suma de los numeros es: %d", suma);
    printf("\nEl producto de los numeros es: %d", producto);
    printf("\nEl cociente de los numeros es: %d", cociente);
    printf("\nEl resto de los numeros es: %d", resto);

    system("pause");
    return 0;
}