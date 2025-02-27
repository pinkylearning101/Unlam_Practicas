/*
    Se ingresan por teclado los datos de los productos de un comercio.  
    Por cada producto se ingresa: 

    Código de producto (de 1 a 9000) 
    Cantidad de unidades en stock (de 1 a 200) 
    Código de rubro al que pertenece (1 a 15) 

    Cómo máximo son 1000 productos. El ingreso de datos finaliza con código cero. 
    
    Se pide: 
    a) Al finalizar el ingreso de datos mostrar código y el mensaje “Alerta, stock 
    insuficiente ” de aquellos productos cuyo stock es menor a 3 unidades. 
    b) Stock promedio. 
    c) Cantidad de productos por rubro.  

    Hacer como mínimo función para la validación de datos y para el ingreso de datos.
*/

#include <stdio.h>
void inicializar (int [], int);
int verificar (int, int, int);
void cargadatos (int [], int [], int [], int []);
void mostrardatos (int [], int [], int []);
void stockpromedio (int []);
void cantidadporrubro (int []);

int main ()
{
    int func_codprod [1000];
    int func_stock [1000];
    int func_rubro [1000];
    int rubros [15]; //no.

    inicializar(func_codprod, 1000);
    inicializar(func_stock, 1000);
    inicializar(func_rubro, 1000);
    inicializar (rubros, 15);

    cargadatos(func_codprod, func_stock, func_rubro ,rubros);
    mostrardatos(func_codprod, func_stock, func_rubro);

    stockpromedio (func_stock);
    cantidadporrubro (rubros);

    return 0;
}
 
void inicializar (int vector [], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        vector[i] = 0;
    }
}

int verificar (int num, int mayor, int menor)
{
    int i;

    while(num < menor || num > mayor)
    {
        printf("Error, ingrese un numero entre %d y %d: ", menor, mayor);
        scanf("%d", &num);
    }
    return num;
}

void cargadatos (int func_codprod [], int func_stock [], int func_rubro [], int rubros [])
{
    int codprod_ingresado, stock_ingresado, rubro_ingresado;
    int contador = 0;
    
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &codprod_ingresado);
    if (codprod_ingresado != 0)
    {
        codprod_ingresado = verificar(codprod_ingresado, 9000, 1);
    }
    
    while( contador < 1000 && codprod_ingresado != 0)
    {
        /////////////////////////////////////////// --------------> request usuario
        printf("Ingrese el stock del producto: ");
        scanf("%d", &stock_ingresado);
        stock_ingresado = verificar(stock_ingresado, 200, 1);

        printf("Ingrese el rubro del producto: ");
        scanf("%d", &rubro_ingresado);
        rubro_ingresado = verificar(rubro_ingresado, 15, 1);
        //////////////////////////////////////// --------------> carga de datos
        func_codprod[contador] = codprod_ingresado;
        func_stock[contador] = stock_ingresado;
        func_rubro[contador] = rubro_ingresado;
        rubros[rubro_ingresado - 1]++;
        contador++;
        ////////////////////////////////////// ---------------> repetir
        
        printf("Ingrese codigo del producto: ");
        scanf("%d", &codprod_ingresado);
        if (codprod_ingresado != 0)
        {
            codprod_ingresado = verificar(codprod_ingresado, 9000, 1);
        }
    }
}

void mostrarmenu (int func_codprod [], int func_stock [], int func_rubro [])
{
    int i;

    printf("Resultado: \n");
    for ( i = 0; i < 1000; i++)
    {
        printf("Producto %d: \n", i+1);
        printf("Codigo: %d\n", func_codprod[i]);
        if (func_stock[i] < 3)
        {
            printf("Alerta, stock insuficiente. Codigo: %d\n", func_codprod[i]);
        }
        else
        {
            printf("Stock: %d\n", func_stock[i]);
        }
        printf("Rubro: %d\n", func_rubro[i]);
    }
} 

void mostrardatos (int func_codprod [], int func_stock [], int func_rubro [])
{
    int i;
    printf("Listado de productos: \n");
    for ( i = 0; i < 1000; i++)
    {
        // if (func_codprod[i] != 0)
        printf("Producto %d - Codigo: %d, Stock: %d, Rubro: %d\n", i+1, func_codprod[i], func_stock[i], func_rubro[i]);
        if (func_stock[i] < 3)
        {
            printf("Alerta, stock insuficiente.\n");
        }
    }
}

void stockpromedio (int func_stock [])
{
    int i;
    int acumulador = 0;
    int contador = 0;
    float promedio;

    for ( i = 0; i < 1000; i++)
    {   
        acumulador += func_stock[i];
        if (func_stock[i] != 0)
        {
            contador++;
        }
    }
    promedio = (float)acumulador / contador;
    printf("El stock promedio es: %.2f\n", promedio);
}

void cantidadporrubro (int rubros [])
{
    int i;
    for ( i = 0; i < 15; i++)
    {
        printf("Rubro %d: %d productos\n", i+1, rubros[i]);
    }
}
