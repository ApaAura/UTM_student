#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "struct.h"

Cinematograf * _cinematografe;
int nr = 0;

void Read()
{
    printf("Dati numarul de cinematografe ce urmeaza a fi introduse: ");
    scanf("%d", &nr);
    _cinematografe = (Cinematograf *)malloc(nr * sizeof(Cinematograf));
    for (int i = 0; i < nr; i++)
    {
        printf("Cinematograf %d\n--------------------------\n", i + 1);
        Cinematograf * c = ReadData();
        _cinematografe[i] = *c;
    }
}

void Show()
{
    for (int i = 0; i < nr; i++)
    {
        PrintData(&_cinematografe[i]);
    }
}

void Search()
{
    char denumirea[50];
    printf("Denumirea cinematografului cautat: ");
    scanf("%s", denumirea);
    for (int i = 0; i < nr; i++)
    {
        if (strcmp(_cinematografe[i].denumirea, denumirea) == 0)
        {
            PrintData(&_cinematografe[i]);
            return;
        }
    }
    printf("Cinematograful nu a fost gasit\n");
}

void Update()
{
    int index = 0;
    printf("Introduceti indexul cinematografului ce urmeaza a fi modificat: ");
    scanf("%d", &index);
    if (index < 0 || index >= nr)
    {
        printf("Indexul introdus nu este valid\n");
        return;
    }
    UpdateData(&_cinematografe[index]);
}

void SortList()
{
    for (int i = 0; i < nr - 1; i++)
    {
        for (int j = i + 1; j < nr; j++)
        {
            if (_cinematografe[i].numarLocuri > _cinematografe[j].numarLocuri)
            {
                swap(&_cinematografe[i], &_cinematografe[j]);
            }
        }
    }
    printf("Cintematografele au fost sortate descredcator dupa numarul de locuri\n");
}

void Delete()
{
    int index = 0;
    printf("Introduceti indexul cinematografului ce urmeaza a fi sters: ");
    scanf("%d", &index);
    if (index < 0 || index >= nr)
    {
        printf("Indexul introdus nu este valid\n");
        return;
    }
    for (int i = index; i < nr - 1; i++)
    {
        _cinematografe[i] = _cinematografe[i + 1];
    }
    nr--;
    _cinematografe = (Cinematograf *)realloc(_cinematografe, nr * sizeof(Cinematograf));
}

void New()
{
    nr++;
    _cinematografe = (Cinematograf *)realloc(_cinematografe, nr * sizeof(Cinematograf));
    printf("Cinematograf %d\n\n--------------------------\n", nr);
    Cinematograf * c = ReadData();
    _cinematografe[nr - 1] = *c;
}

void Import()
{
    FILE * f = fopen("cinematografe.bin", "rb");
    if (f == NULL)
    {
        printf("Fisierul nu a fost gasit\n");
        return;
    }
    fread(&nr, sizeof(int), 1, f);
    _cinematografe = (Cinematograf *)malloc(nr * sizeof(Cinematograf));
    fread(_cinematografe, sizeof(Cinematograf), nr, f);
    fclose(f);
}

void Export()
{
    FILE * f = fopen("cinematografe.bin", "wb");
    fwrite(&nr, sizeof(int), 1, f);
    fwrite(_cinematografe, sizeof(Cinematograf), nr, f);
    fclose(f);
}

void FileDelete()
{
    if (remove("cinematografe.bin") == 0)
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
    printf("1 . \tCitire cinematografe\n");
    printf("2 . \tAfisare cinematografe\n");
    printf("3 . \tCautare cinematograf\n");
    printf("4 . \tActualizare cinematograf\n");
    printf("5 . \tSortare cinematografe\n");
    printf("6 . \tStergere cinematograf\n");
    printf("7 . \tAdauga cinematograf la sfarsit\n");
    printf("8 . \tImport cinematografe din fisier binar\n");
    printf("9 . \tExport cinematografe din fisier binar\n");
    printf("10 . \tSterge fisierul binar\n");
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
            free(_cinematografe);
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