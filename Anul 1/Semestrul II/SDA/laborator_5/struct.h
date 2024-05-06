#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Imobil { 
    char proprietar[100]; 
    char tip[100]; 
    char adresa[15]; 
    float suprafata; 
    int cost; 
} Imobil;

Imobil * ReadData()
{
    Imobil *c = (Imobil *)malloc(sizeof(Imobil));
    printf("--------------------------------\n");
    printf("Denumirea: ");
    fflush(stdin);
    scanf("%s", c->proprietar);
    printf("Adresa: ");
    fflush(stdin);
    scanf("%s", c->adresa);
    printf("Tipul: ");
    fflush(stdin);
    scanf("%s", c->tip);
    printf("Suprafata: ");
    fflush(stdin);
    scanf("%f", &c->suprafata);
    printf("Costul: ");
    fflush(stdin);
    scanf("%d", &c->cost);
    printf("--------------------------------\n");
    return c;
}

char * ToString(Imobil * c)
{
    char * str = (char *)malloc(1000 * sizeof(char));
    sprintf(str, "Proprietar: %s\nAdresa: %s\nTipul: %s\nSuprafata: %.2f\nCostul: %d\n", c->proprietar, c->adresa, c->tip, c->suprafata, c->cost);
    return str;
}

void PrintData(Imobil *c)
{
    printf("\n--------------------------------\n");
    printf("Proprietar: %s\n", c->proprietar);
    printf("Adresa: %s\n", c->adresa);
    printf("Tipul: %s\n", c->tip);
    printf("Suprafata: %.2f\n", c->suprafata);
    printf("Costul: %d\n", c->cost);
    printf("--------------------------------\n");
}
void UpdateData(Imobil * c)
{
    char resp;
    printf("Modificati proprietarul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Proprietarul noua:\t");
        scanf("%s", c->proprietar);
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
    printf("Modificati tipul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Tipul nou:\t");
        scanf("%s", c->tip);
    }
    printf("Modificati suprafata?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Suprafata noua:\t");
        scanf("%f", &c->suprafata);
    }
    printf("Modificati costul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("costul nou:\t");
        scanf("%d", &c->cost);
    }
}

void swap(Imobil *a, Imobil *b)
{
    Imobil aux = *a;
    *a = *b;
    *b = aux;
}