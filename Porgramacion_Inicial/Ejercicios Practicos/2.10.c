/*
Confeccionar un programa que solicite el ingreso del valor del radio (r) de
un círculo y con dicho valor calcule la superficie del círculo, la longitud
de la circunferencia (perímetro) y el volumen de la esfera.                          

𝑆𝑢𝑝𝑒𝑟𝑓𝑖𝑐𝑖𝑒=𝜋𝑟2 
𝑃𝑒𝑟í𝑚𝑒𝑡𝑟𝑜= 2𝜋𝑟 
𝑉𝑜𝑙ú𝑚𝑒𝑛=3/4𝜋
*/

#include <stdio.h>
#define PI 3.14159265359

int main ()
{
    int radio;
    float superficie, perimetro, volumen;

    printf("\nIngrese el radio del circulo: ");
    scanf(" %d", &radio);

    superficie = PI * radio * radio;
    perimetro = 2 * PI * radio;
    volumen = (3/4) * PI * (radio * radio * radio);

    printf("\nLa superficie del circulo es de %.2f", superficie);
    printf("\nEl perimetro del circulo es de %.2f", perimetro);
    printf("\nEl volumen de la esfera es de %.2f", volumen);

    system("pause");
    return 0;
}