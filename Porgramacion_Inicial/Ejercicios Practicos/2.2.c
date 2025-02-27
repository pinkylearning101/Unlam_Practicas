/*
2.2. Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.
*/

#include <stdio.h>

int main ()
{
    int nota1,nota2;
    float promedio;

    printf("\nIngrese la primer nota: ");
    scanf(" %d", &nota1);

    printf("\nIngrese la segunda nota: ");
    scanf(" %d", &nota2);

    promedio = (nota1 + nota2) / 2;

    printf("\nEl promedio de las notas es: %.2f", promedio);
    
    system("pause");
    return 0;
}