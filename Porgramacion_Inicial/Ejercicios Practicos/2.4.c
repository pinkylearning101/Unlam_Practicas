/*
2.4. Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas, pulgadas, cms.
y mts. 
    NOTA: 1 pie = 12 pulgadas;
    1 yarda = 3 pies; 
    1 pulgada = 2,54 cms.
*/
#include <stdio.h>

int main ()
{
    int medida, yardas, pulgadas;
    float cms, mts;

    printf("\nIngrese la medida en pies: ");
    scanf(" %d", &medida);

    // <--- Mas practica aca 
    pulgadas = medida * 12;
    yardas = medida / 3;
    cms = pulgadas * 2.54; 

    printf("\nLa medida en yardas es de %d", yardas);
    printf("\nLa medida en pulgadas es de %d", pulgadas);
    printf("\nLa medida en cms es de %.2f", cms);

    System("pause");
    return 0;
}