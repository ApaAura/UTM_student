#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct  Car { 
 char model[50]; 
 char country[30]; 
 char manufacturing_date[15]; 
 float engine_power; 
 float cost;  
} Car;

Car * ReadData()
{
    Car *c = (Car *)malloc(sizeof(Car));
    printf("Introduceti modelul: ");
    fflush(stdin);
    gets(c->model);
    printf("Introduceti tara de provenienta: ");
    fflush(stdin);
    gets(c->country);
    printf("Introduceti data de fabricatie: ");
    fflush(stdin);
    gets(c->manufacturing_date);
    printf("Introduceti puterea motorului: ");
    fflush(stdin);
    scanf("%f", &c->engine_power);
    printf("Introduceti costul: ");
    fflush(stdin);
    scanf("%f", &c->cost);
    return c;
}

void PrintData(Car *c)
{
    printf("\n--------------------------------\n");
    printf("Modelul: %s\n", c->model);
    printf("Tara de provenienta: %s\n", c->country);
    printf("Data de fabricatie: %s\n", c->manufacturing_date);
    printf("Puterea motorului: %.2f\n", c->engine_power);
    printf("Costul: %.2f\n", c->cost);
    printf("\n--------------------------------\n");
}
void UpdateData(Car * c)
{
    char resp;
    printf("Modificati modelul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Modelul nou:\t");
        scanf("%s", c->model);
    }
    printf("Modificati tara de provenienta?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Tara de provenienta noua:\t");
        scanf("%s", c->country);
    }
    printf("Modificati data de fabricare?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Data de fabricare noua:\t");
        scanf("%s", c->manufacturing_date);
    }
    printf("Modificati puterea motorului?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Puterea noua a motorului:\t");
        scanf("%d", &c->engine_power);
    }
    printf("Modificati costul?(y/n) ->");
    fflush(stdin);
    scanf("%c", &resp);
    if (tolower(resp) == 'y')
    {
        fflush(stdin);
        printf("Costul nou:\t");
        scanf("%f", &c->cost);
    }
}

Car * FromString(char * str)
{
    Car * c = (Car *)malloc(sizeof(Car));
    sscanf(str, "%[^_]_|_%[^_]_|_%[^_]_|_%f_|_%f\n", c->model, c->country, c->manufacturing_date, &c->engine_power, &c->cost);
    return c;
}

char * ToString(Car c)
{
    char * str = (char *)malloc(103);
    sprintf(str, "%s_|_%s_|_%s_|_%f_|_%f\n", c.model, c.country, c.manufacturing_date, c.engine_power, c.cost);
    return str;
}

void swap(Car *a, Car *b)
{
    Car aux = *a;
    *a = *b;
    *b = aux;
}