/*
Una farmacia desea contabilizar las ventas realizadas de sus 100 productos. 
Para ello cuenta con la siguiente información:

•	Código de producto (entero, entre 1 y 100)
•	Importe del producto (real, mayor a cero)
•	Cantidad de unidades vendidas (entero, mayor a cero)

La carga de las ventas finaliza con código de producto igual a cero.
Puede ocurrir que un producto tenga ninguna, una o más ventas.
Se pide desarrollar un programa en lenguaje c o el correspondiente 
diagrama para:

1.	Informar para cada producto el código de producto y cantidad vendida.
2.	Informar el o los códigos de productos con mayor cantidad de unidades vendidas.
3.	Informar el total recaudado de productos vendidos.		
*/

#include <stdio.h>
#define CANTIDAD 100

void cargardatos (int [], float[]);
void mostrardatos (int [], float[]);
void inicializarint (int [], int);
void inicializarfloat (float [], int);
int verificar (int, int, int, int);
void mostrarcant (int []);
void mostrarrecaudado (float []);

int main ()
{
    int cantidad[CANTIDAD];
    float importe[CANTIDAD];

    inicializarfloat(importe, CANTIDAD);
    inicializarint(cantidad, CANTIDAD);

    cargardatos(cantidad, importe);
    mostrardatos(cantidad, importe);

    mostrarcant(cantidad);
    mostrarrecaudado(importe);

    return 0;
}

void cargardatos (int cantidad[], float importe [])
{
    int i;
    int codigo_ingresado, cantidad_ingresada;
    float importe_ingesado;

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigo_ingresado);
    codigo_ingresado = verificar(codigo_ingresado, 100, 1, 0);

    while (codigo_ingresado!= 0)
    {
        /////////////////////////////// ----------------> request usuario
        printf("Ingrese el importe del producto: ");
        scanf("%f", &importe_ingesado);
        while (importe_ingesado <= 0)
        {
            printf("Error, ingrese un importe mayor a 0: ");
            scanf("%f", &importe_ingesado);
        }
        
        printf("Ingrese la cantidad de unidades vendidas: ");
        scanf("%d", &cantidad_ingresada);
        while (cantidad_ingresada <= 0)
        {
            printf("Error, ingrese una cantidad mayor a 0: ");
            scanf("%d", &cantidad_ingresada);
        }
        /////////////////////////////// ----------------> carga datos en los vectores

        cantidad[codigo_ingresado - 1] += cantidad_ingresada;
        importe[codigo_ingresado - 1] = importe_ingesado;   

        /////////////////////////////// ----------------> repeticion

        printf("Ingrese el codigo del producto: ");
        scanf("%d", &codigo_ingresado);
        codigo_ingresado = verificar(codigo_ingresado, 100, 1, 0);
    }
 }

void mostrardatos (int cantidad[], float importe [])
{
    int i;

    for ( i = 0; i < CANTIDAD; i++)
    {
        /* ----------------> muestra los productos con cantidad vendida
        if (cantidad[i] != 0)
        {
            printf("Producto %d: \n", i+1);
            printf("Cantidad vendida: %d\n", cantidad[i]);
            printf("Importe total: %.2f\n", importe[i]);
        }
        */ //----------> muestra todos los productos

        printf("\nResultados: \n");
        printf("Producto %d: \n", i+1);
        printf("Cantidad vendida: %d\n", cantidad[i]);
        printf("Importe total: %.2f\n", importe[i]);
    }
}

void inicializarint (int vector [], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

void inicializarfloat (float vector [], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

int verificar (int num, int mayor, int menor, int flag)
{
    while ((num  < menor || num > mayor) && flag != 0)
    {
        printf("Error, ingrese un numero entre %d y %d: ", menor, mayor);
        scanf("%d", &num);
    }
    return num;
}

void mostrarcant (int vec_cantidad[])
{
    int mayornum, contador = 0;
    int i;

    int vec_mostrar_iguales[CANTIDAD];

    for ( i = 0; i < CANTIDAD; i++)
    {
     if (vec_cantidad[i] > mayornum)
     {
        mayornum = vec_cantidad[i];
     }
    }
    for ( i = 0; i < CANTIDAD; i++)
    {
        if (vec_cantidad[i] == mayornum)
        {
            vec_mostrar_iguales[contador] = vec_cantidad[i];
            contador++;
        }
    }

    printf("Los productos con mayor cantidad de unidades vendidas son: \n");
    for ( i = 0; i < contador; i++)
    {
     printf("Producto %d: %d unidades vendidas\n", i+1, vec_mostrar_iguales[i]);
    }
}

void mostrarrecaudado (float vec_importe[])
{
    int i;
    float sumatotal = 0;

    for ( i = 0; i < CANTIDAD; i++)
    {
        if (vec_importe[i] != 0)
        {
            sumatotal += vec_importe[i];
        }
    }
    printf("El total recaudado de productos vendidos es: %.2f\n", sumatotal);
}