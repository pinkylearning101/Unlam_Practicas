/*
Confeccionar  un  programa  que  ingrese  un  valor expresado en  Kibibyte (KiB)1 y  lo  informe  expresado  en:  
TiB, GiB, MiB, con leyendas aclaratorias. 

    MiB = 1024 KiB
    1GiB = 1024 MiB
    1TiB = 1024 GiB
*/ 

#include <stdio.h>

int main ()
{
    //int kib, mib, gib, tib; (para que no tengas que pensar despues de la coma)
    float kib, mib, gib, tib;

    printf("\nIngrese un valor expresado en Kibibyte (KiB): ");
    scanf(" %f", &kib);

    //Tomando por ejemplo: 154,333 kib
    mib = kib / 1024; 
    gib = mib / 1024;
    tib = gib / 1024;

    printf("\nEl valor en MiB es de %.2f", mib);
    printf("\nEl valor en GiB es de %.2f", gib);
    printf("\nEl valor en TiB es de %.2f", tib);

    system("pause");
    return 0;
}