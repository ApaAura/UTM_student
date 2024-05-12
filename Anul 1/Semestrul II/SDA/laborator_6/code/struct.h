#include <stdio.h>
#include <stdlib.h>

//denumirea, adresa, telefonul, orele de lucru, volumul de medicamente.
typedef struct Farmacie
{
    char denumire[100];
    char adresa[100];
    char telefon[100];
    char oreLucru[100];
    int volumMedicamente;
} Farmacie;

Farmacie * ReadStruct()
{
    Farmacie * c = (Farmacie * )malloc(sizeof(Farmacie));
    printf("Dati datele Farmaciei:\n===============================\n");
    printf("Denumire:\t");
    fflush(stdin);
    gets(c->denumire);
    printf("Adresa:\t");
    fflush(stdin);
    gets(c->adresa);
    printf("Telefon:\t");
    fflush(stdin);
    gets(c->telefon);
    printf("Ore de lucru:\t");
    fflush(stdin);
    gets(c->oreLucru);
    printf("Volum medicamente:\t");
    fflush(stdin);
    scanf("%d", &c->volumMedicamente);
    return c;
}

void ShowStruct(Farmacie * c, int id)
{
    if (c==NULL)
    {
        printf("null reference exception");
        return;
    }
    printf("===================================\n");
    printf("Farmacie %d:\n", id);
    printf("Denumire:\t%s\n", c->denumire);
    printf("Adresa:\t%s\n", c->adresa);
    printf("Telefon:\t%s\n", c->telefon);
    printf("Ore de lucru:\t%s\n", c->oreLucru);
    printf("Volum medicamente:\t%d\n", c->volumMedicamente);
    printf("===================================\n");
}

char * ToString(Farmacie * c)
{
    char * str = (char *)malloc(1000);
    sprintf(str, "%s_|_%s_|_%s_|_%s_|_%d\n", c->denumire, c->adresa, c->telefon, c->oreLucru, c->volumMedicamente);
    return str;
}

Farmacie * FromString(char * str)
{
    Farmacie * c = (Farmacie *)malloc(sizeof(Farmacie));
    sscanf(str, "%[^_]_|_%[^_]_|_%[^_]_|_%[^_]_|_%d\n", c->denumire, c->adresa, c->telefon, c->oreLucru, &c->volumMedicamente);
    return c;
}

void ModifyStruct(Farmacie * c)
{
    char resp;
    printf("Modificati denumirea farmaciei?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp)=='y')
    {
        fflush(stdin);
        printf("Denumirea farmaciei:\t"); 
        gets(c->denumire);
    }
    printf("Modificati adresa farmaciei?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp)=='y')
    {
        fflush(stdin);
        printf("Adresa farmaciei:\t"); 
        gets(c->adresa);
    }
    printf("Modificati telefonul farmaciei?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp)=='y')
    {
        fflush(stdin);
        printf("Telefonul farmaciei:\t"); 
        gets(c->telefon);
    }
    printf("Modificati orele de lucru?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp)=='y')
    {
        fflush(stdin);
        printf("Orele de lucru:\t"); 
        gets(c->oreLucru);
    }
    printf("Modificati volumul de medicamente?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp)=='y')
    {
        fflush(stdin);
        printf("Volumul de medicamente:\t"); 
        scanf("%d", &c->volumMedicamente);
    }
}