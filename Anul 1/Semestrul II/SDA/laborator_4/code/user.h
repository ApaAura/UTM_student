#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "struct.h"

Car * _masini;
int nr = 0;

void Read()
{
    printf("Dati numarul de masini ce urmeaza a fi introduse: ");
    scanf("%d", &nr);
    _masini = (Car *)malloc(nr * sizeof(Car));
    for (int i = 0; i < nr; i++)
    {
        printf("Car %d\n--------------------------\n", i + 1);
        Car * c = ReadData();
        _masini[i] = *c;
    }
}

void Show()
{
    for (int i = 0; i < nr; i++)
    {
        PrintData(&_masini[i]);
    }
}

void Search()
{
    char mod[50];
    printf("Modelul masinii cautate: ");
    scanf("%s", mod);
    for (int i = 0; i < nr; i++)
    {
        if (strcmp(_masini[i].model, mod) == 0)
        {
            PrintData(&_masini[i]);
            return;
        }
    }
    printf("Masina nu a fost gasit\n");
}

void Update()
{
    int index = 0;
    printf("Introduceti indexul masinii ce urmeaza a fi modificata: ");
    scanf("%d", &index);
    if (index < 0 || index >= nr)
    {
        printf("Indexul introdus nu este valid\n");
        return;
    }
    UpdateData(&_masini[index]);
}

void SortList()
{
    for (int i = 0; i < nr - 1; i++)
    {
        for (int j = i + 1; j < nr; j++)
        {
            if (_masini[i].engine_power > _masini[j].engine_power)
            {
                swap(&_masini[i], &_masini[j]);
            }
        }
    }
    printf("Masinile au fost sortate dupa puterea motorului\n");
}

void Delete()
{
    int index = 0;
    printf("Introduceti indexul masinii ce urmeaza a fi sterse: ");
    scanf("%d", &index);
    if (index < 0 || index >= nr)
    {
        printf("Indexul introdus nu este valid\n");
        return;
    }
    for (int i = index; i < nr - 1; i++)
    {
        _masini[i] = _masini[i + 1];
    }
    nr--;
    _masini = (Car *)realloc(_masini, nr * sizeof(Car));
}

void New()
{
    nr++;
    _masini = (Car *)realloc(_masini, nr * sizeof(Car));
    printf("Car %d\n\n--------------------------\n", nr);
    Car * c = ReadData();
    _masini[nr - 1] = *c;
}

void Import()
{
    FILE * f = fopen("Cars.txt", "r");
    if (f == NULL)
    {
        printf("Fisierul nu a fost gasit\n");
        return;
    }
    fread(&nr, sizeof(int), 1, f);
    _masini = (Car *)malloc(nr * sizeof(Car));
    char * buffer = (char *)malloc(103);
    for(int i = 0; i < nr; i++)
    {
        fgets(buffer, 103, f);
        _masini[i] = *FromString(buffer);
    }
    fclose(f);
}

void Export()
{
    FILE * f = fopen("Cars.txt", "w");
    fwrite(&nr, sizeof(int), 1, f);
    for(int i = 0; i < nr; i++)
    {
        fprintf(f, "%s", ToString(_masini[i]));
    }
    fclose(f);
}

void FileDelete()
{
    if (remove("Cars.txt") == 0)
    {
        printf("Fisierul a fost sters cu succes\n");
    }
    else
    {
        printf("Fisierul nu a putut fi sters\n");
    }

}

int userChose = 0;
int go = 1;

int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tCitire date masina\n");
    printf("2 . \tAfisare date masina\n");
    printf("3 . \tCautare masina\n");
    printf("4 . \tActualizare date masina\n");
    printf("5 . \tSortare masini\n");
    printf("6 . \tStergere masina\n");
    printf("7 . \tAdauga masina la sfarsit\n");
    printf("8 . \tImport masini din fisier text\n");
    printf("9 . \tExport masini din fisier text\n");
    printf("10 . \tSterge fisierul text\n");
    printf("11 . \tElibereaza memoria\n");
    printf("0 . \tExit\n");
    printf("---------------------------------------------------------------------\nOptiunea aleasa --> ");
    int op;
    scanf("%d", &op);
    system("cls");
    return op;
}

void PressAnyKey()
{
    printf("\nAtingeti o tasta pentru a continua\n");
    getch();
    system("cls");
}

void BL()
{
    switch (userChose)
    {
        case 1: 
        {
            Read();
            PressAnyKey();
        } break;
        case 2:
        {
            Show();
            PressAnyKey();
        }break;
        case 3:
        {
            Search();
            PressAnyKey();
        }break;
        case 4:
        {
            Update();
            PressAnyKey();
        }break;
        case 5:
        {
            SortList();
            PressAnyKey();
        }break;
        case 6:
        {
            Delete();
            PressAnyKey();
        }break;
        case 7:
        {
            New();
            PressAnyKey();
        }break;
        case 8:
        {
            Import();
            PressAnyKey();
        }break;
        case 9:
        {
            Export();
            PressAnyKey();
        }break;
        case 10:
        {
            FileDelete();
            PressAnyKey();
        }break;
        case 11:
        {
            free(_masini);
            nr = 0;
            PressAnyKey();
        }break;
        case 0:
        {
            go=0;
            system("cls");
            printf("Aplicatia s-a oprit cu succes");
            getch();
        }break;
        default:printf("Optiune necunoscuta\nIncercati din nou");break;
    }
}