/*
Se ingresan por teclado los datos de los estudiantes de un instituto de enseñanza.  
Por cada estudiante se ingresa: 

Número de legajo (de 1 a 1000) 
Nota obtenida en el curso (de 1 a 10) 
Curso en el que está inscripto (1 a 5) 

Cómo máximo son 500 estudiantes. El ingreso de datos finaliza con legajo cero. 
Se pide: 
a) Al finalizar el ingreso de datos mostrar legajo y el mensaje “Aprobado” si nota es mayor o 
igual a 4 y “Desaprobado” si nota menor a 4, para todos los estudiantes. 
b) Nota promedio. 
c) Cantidad de estudiantes por curso.  
Hacer como mínimo función para la validación de datos y para el ingreso de datos. 
*/

#include <stdio.h>

void inicializar (int[],int);
int verificacion (int,int,int);
void cargadatos (int[], int[], int[], int[]);
void mostrarmenu (int[], int[], int[]);
void mostrarpromedio (int[]);
void mostrarcantidad (int[]);

int main () 
{   
    int legajo[500];
    int nota[500];
    int mostrarcurso[500];
    int curso [5];

    inicializar (legajo, 500);
    inicializar (nota, 500);
    inicializar (mostrarcurso, 500);
    inicializar (curso, 5);

    cargadatos (legajo, nota, curso, mostrarcurso);
    
    mostrarmenu (legajo, nota, mostrarcurso);
    mostrarpromedio (nota);
    mostrarcantidad (curso);
    return 0;
}

void inicializar (int legajo [], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        legajo[i] = 0;
    }
}

int verificacion (int num, int mayor, int menor)
{
    while (num < menor || num > mayor)
    {
        printf("Error. ");
        printf("Ingrese un numero entre %d y %d: ", menor, mayor);
        scanf("%d", &num);
    }
    return num;
}

void cargadatos (int veclegajo [], int vecnota [], int veccurso [], int vecmostrarcurso [])
{
    int contador = 0;
    int legajo_ingresado, nota_ingresada, curso_ingresado;

    printf("Ingrese legajo (1 a 1000, 0 para finalizar): ");
    scanf("%d", &legajo_ingresado);
    legajo_ingresado= verificacion(legajo_ingresado, 1000, 0);

    while (legajo_ingresado != 0 && contador < 500)
    {
        ///////////////////////////////////// ------------> carga de datos
        printf ("Ingrese nota (1 a 10): ");
        scanf("%d", &nota_ingresada);
        nota_ingresada = verificacion(nota_ingresada, 10, 1);

        printf("Ingrese curso (1 a 5): ");
        scanf("%d", &curso_ingresado);
        curso_ingresado = verificacion(curso_ingresado, 5, 1);

        ///////////////////////////////////// ------------> poner? datos?

        veclegajo[contador] = legajo_ingresado;
        vecnota[contador] = nota_ingresada;
        vecmostrarcurso[contador] = curso_ingresado;
        
        veccurso[curso_ingresado-1]++;
        contador++;
        ///////////////////////////////////// ------------> repetir
        printf("Ingrese legajo (1 a 1000, 0 para finalizar): ");
        scanf("%d", &legajo_ingresado);
        legajo_ingresado = verificacion(legajo_ingresado, 1000, 0);
    }
}

void  mostrarmenu (int legajo [], int nota [], int mostrarcurso [])
{
    int i;

    printf("\nResultados:\n");
    printf("\nEstudiante: (tab) Legajo: (tab) Nota: (tab) Curso: (tab) Estado:\n");

    for ( i = 0; i < 500; i++)
    {
        // if (legajo[i] != 0) {  // Solo mostrar estudiantes ingresados

        if (legajo[i] != 0)
        {
            printf("%d (tab) %d (tab) %d (tab) %d (tab)",i+1, legajo[i],nota[i], mostrarcurso[i]);
            if (nota[i] < 4)
            {
            printf("Desaprobado\n");
            }
            else
            {
            printf("Aprobado\n");
            }
        }
    }
}

void mostrarpromedio (int nota [])
{
    int i;
    int sumatotal = 0, contadorestudiante = 0;
    float promedio = 0;

    for ( i = 0; i < 500 ; i++)
    {
        if (nota[i] > 0)
        {
            sumatotal += nota[i];
            contadorestudiante++;
        }
    }

    promedio = (float)sumatotal / contadorestudiante;  /////////// ------------> promedio (duda sobre forzar)
    printf("\nNota promedio: %.2f\n", promedio); 
}

void mostrarcantidad (int curso [])
{
    int i;
    printf("\nCantidad de estudiantes por curso:\n");

    for ( i = 0; i < 5; i++)
    {
        printf("Curso %d: %d estudiantes\n", i+1, curso[i]);
    }
}