/*
Versión 2
Una farmacia desea contabilizar las ventas realizadas de sus 100 productos. Para ello cuenta con la siguiente información:

•	Código de producto (entero, entre 1 y 100)
•	Importe del producto (real, mayor a cero)

Primero se carga los importes para cada producto. -> for() para cargar el importe de cada producto
Luego se carga las ventas finalizando con código de producto igual a cero. Puede ocurrir que un producto
tenga ninguna, una o más ventas. Se ingresa:

•	Código de producto (entero, entre 1 y 100)
•	Cantidad de unidades vendidas (entero, mayor a cero)

Se pide desarrollar un programa en lenguaje c o el correspondiente diagrama para:
1.	Informar para cada producto el código de producto y cantidad vendida.
2.	Informar el o los códigos de productos con mayor cantidad de unidades vendidas.
3.	Informar el total recaudado de productos vendidos.
*/
#include <stdio.h>
void cargadatos (int [], float []);
void inicializarint (int [], int);

int main ()
{
    float importe [100];
    int ventas [100];

    inicializarint (ventas, 100);
    cargadatos (ventas, importe);

    mostrarresultados (ventas,importe);
    mostrarmayorcant (ventas);
    totalrecaudado (ventas, importe);

    return 0;
}

void inicializarint (int vector [], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

void cargadatos (int ventas [], float importe [])
{
    int i;
    int codigo_ingresado, ventas_ingresadas;
    
    for ( i = 0; i < 100; i++)
    {
        ///////////////////////////// --------------------------> precios
        printf("Ingrese el importe del producto %d: ", i+1);
        scanf("%f", &importe[i]);
        while (importe < 0)
        {
            printf("Error, ingrese un importe mayor a 0: ");
            scanf("%f", &importe[i]);
        }
    }
    
    ///////////////////////////////////// -----------------------> ventas
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigo_ingresado);
    if (codigo_ingresado != 0)
    {
        verificar(codigo_ingresado, 100, 1);
    }

    while (codigo_ingresado != 0)
    {
        printf("Ingrese la cantidad de unidades vendidas: ");
        scanf("%d", &ventas_ingresadas);
        while (ventas_ingresadas <= 0)
        {
            printf("Error, ingrese una cantidad mayor a 0: ");
            scanf("%d", &ventas_ingresadas);
        }

        ventas[codigo_ingresado - 1] += ventas_ingresadas;

        ////////////////////////////////// ------------------> repetir
        printf("Ingrese el codigo del producto: ");
        scanf("%d", &codigo_ingresado);
        if (codigo_ingresado != 0)
        {
            verificar (codigo_ingresado, 100, 1);
        }
    }
}

int verificar (int num, int mayor, int menor)
{
    while (num  < menor || num > mayor)
    {
        printf("Error, ingrese un numero entre %d y %d: ", menor, mayor);
        scanf("%d", &num);
    }
    return num;
}

void mostrarresultados (int ventas [], float importe [])
{
    for (int i = 0; i < 100; i++)
    {
        if (ventas[i] != 0)
        {
            printf("Producto %d: %d unidades vendidas a un precio de %.2f\n", i+1, ventas[i], importe[i]);
        }  
    }
}

void mostrarmayorcant (int ventas [])
{
    int mayornum = 0 , contador = 0;
    int codigomayor, i;
    int vectorcodigos [100];

    for ( i = 0; i < 100; i++)
    {
        if (ventas[i] > mayornum)
        {
            mayornum = ventas[i];
            codigomayor = i+1;
        }
    }
    
    for (i = 0; i < 100; i++)
    {
        if (mayornum == ventas[i])
        {
            vectorcodigos[contador] = i+1;
            contador++;
        }
    }

    for ( i = 0; i < contador; i++)
    {
        printf("\nEl codigo del producto %d vendio : %d ", codigomayor, mayornum);
        if (contador > 1)
        {
            printf("\nTambien los productos:");
            for ( i = 0; i < contador; i++)
            {
                printf("%d ", vectorcodigos[i]);
            }
        }      
    }
}

void totalrecaudado (int ventas[], float importe [])
{
    int i;
    int sumatotal = 0, cantproductos = 0;
    float promedio;

    for ( i = 0; i < 100; i++)
    {
        if (ventas[i] != 0)
        {
            sumatotal += ventas[i] * importe[i];
            cantproductos += ventas[i];
        }
    }

    promedio = sumatotal / cantproductos;
    printf("\nEl total recaudado por la farmacia es de: %.2f\n", sumatotal);
}