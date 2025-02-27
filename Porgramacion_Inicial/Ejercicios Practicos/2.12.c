/*
Una  farmacia  vende  algunos  artículos  sin  descuento  y  a  otros
con  descuento  del  20%.  Confeccionar  un programa  que  recibiendo
el  precio  original  y  un  código  que  indica  si  es  o  no  con
descuento,  informe  el precio final (0 no aplica el descuento y 1 
aplica el descuento)
*/

#include <stdio.h>

int main ()
{
    float precio;
    int codigo;

    printf("\nIngrese el precio del articulo: ");
    scanf(" %f", &precio);
    printf("\nIngrese el codigo del articulo (0 sin descuento, 1 con descuento): ");  
    scanf(" %d", &codigo);

    if (codigo == 0)
    {
        printf("\nNo aplica descuento");
        printf("\nEl precio final del articulo es de %.2f", precio);
    }
    else
    {
        printf("\nAplica descuento del 20%");
        printf("\nEl precio final del articulo es de %.2f", precio * 0.8); //aca toma el %80 directamente
        /*
            Alternativa: 
            precio_final = precio - (precio * 0.2);
        */
    }

    system("pause");
    return 0;
}