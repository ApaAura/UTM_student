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

void ChooseSortMethod(){
    int optiune = 0;
    printf("1. Sortare crescatoare bubbleSort\n"); 
    printf("2. Sortare descrescatoare bubbleSort\n"); 
    printf("3. Sortare crescatoare mergeSort\n"); 
    printf("4. Sortare descrescatoare mergeSort\n"); 
    printf("Alegeti o optiune: "); 
    scanf("%d", &optiune); 
    if (optiune == 1) { 
        BubbleSortCrescator();
    } else if (optiune == 2) { 
        BubbleSortDescrescator();
    } else if (optiune == 3) {
        MergeSortCrescator() ;
    } else if (optiune == 4) { 
        void MergeSortDescrescator();
    } else { 
        printf("Optiune invalida!\n"); 
    } 
}

void  BubbleSortCrescator()
{
     for (int i = 0; i < nr - 1; i++)
    {
        for (int j = i + 1; j < nr; j++)
        {
            if (_cinematografe[i].numarLocuri < _cinematografe[j].numarLocuri)
            {
                swap(&_cinematografe[i], &_cinematografe[j]);
            }
        }
    }
    printf("Cinematografele au fost sortate crescator dupa numarul de locuri\n");
}

void  BubbleSortDescrescator()
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
    printf("Cinematografele au fost sortate descrescator dupa numarul de locuri\n");
}

void MergeSortCrescator(){

}

void MergeSortDescrescator(){
    
}

int userChose = 0;
int go = 1;

int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tCitire cinematografe\n");
    printf("2 . \tAfisare cinematografe\n");
    printf("3 . \tSortare cinematografe\n");
    printf("4 . \tElibereaza memoria\n");
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
            ChooseSortMethod();
            PressAnyKey();
        }break; 
        case 4:
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