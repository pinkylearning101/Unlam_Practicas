/*
    El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase. 
    Se ingresan la cantidad de pasajes vendidos de clase turista y de primera clase. 
    Obtener la recaudación total del vuelo
*/

#include <stdio.h>

int main ()
{
    int turista, primera;
    float recaudacion; 
    
    printf("\nIngrese la cantidad de pasajes vendidos en clase turista: ");
    scanf(" %d", &turista);
    printf("\nIngrese la cantidad de pasajes vendidos en primera clase: ");
    scanf(" %d", &primera);

   recaudacion += turista * 8800;
   recaudacion += primera * (8800 * 1.3); //el boleto + 30% de incremento

   printf("\nLa recaudacion total del vuelo es de %.2f", recaudacion);
    
    system("pause");
    return 0;
}