/*
2.8. Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a un 
número con formato (aammdd)
*/

#include <stdio.h>

int main ()
{
    int fecha, dia, mes, anio, nueva_fecha;

    printf("\nIngrese una fecha con formato (ddmmaa): ");
    scanf(" %d", &fecha);

    dia = fecha / 10000;
    mes = (fecha / 100) % 100;
    anio = fecha % 100;

    nueva_fecha = anio * 10000 + mes * 100 + dia;

    printf("\nLa fecha con formato (aammdd) es: %d", nueva_fecha);
    system("pause");
    return 0;
}