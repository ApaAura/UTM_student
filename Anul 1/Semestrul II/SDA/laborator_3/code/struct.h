#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Cinematograf { 
    char denumirea[50]; 
    char adresa[100]; 
    char telefonul[15]; 
    int numarLocuri; 
    float pretBilete; 
} Cinematograf;

Cinematograf * ReadData()
{
    Cinematograf *c = (Cinematograf *)malloc(sizeof(Cinematograf));
    printf("Denumirea: ");
    fflush(stdin);
    scanf("%s", c->denumirea);
    printf("Adresa: ");
    fflush(stdin);
    scanf("%s", c->adresa);
    printf("Telefonul: ");
    fflush(stdin);
    scanf("%s", c->telefonul);
    printf("Numarul de locuri: ");
    fflush(stdin);
    scanf("%d", &c->numarLocuri);
    printf("Pretul biletelor: ");
    fflush(stdin);
    scanf("%f", &c->pretBilete);
    return c;
}

void PrintData(Cinematograf *c)
{
    printf("\n--------------------------------\n");
    printf("Denumirea: %s\n", c->denumirea);
    printf("Adresa: %s\n", c->adresa);
    printf("Telefonul: %s\n", c->telefonul);
    printf("Numarul de locuri: %d\n", c->numarLocuri);
    printf("Pretul biletelor: %.2f\n", c->pretBilete);
    printf("\n--------------------------------\n");
}
void UpdateData(Cinematograf * c)
{
    char resp;
    printf("Modificati denumirea?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Denumirea noua:\t");
        scanf("%s", c->denumirea);
    }
    printf("Modificati adresa?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Adresa noua:\t");
        scanf("%s", c->adresa);
    }
    printf("Modificati telefonul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Telefonul nou:\t");
        scanf("%s", c->telefonul);
    }
    printf("Modificati numarul de locuri?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Numarul de locuri nou:\t");
        scanf("%d", &c->numarLocuri);
    }
    printf("Modificati pretul biletelor?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Pretul biletelor nou:\t");
        scanf("%f", &c->pretBilete);
    }
}

void swap(Cinematograf *a, Cinematograf *b)
{
    Cinematograf aux = *a;
    *a = *b;
    *b = aux;
}