#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "struct.h"
#include "Stack.h"
#include "Queue.h"

Stack * s;
queue * q;
int nr = 0;

void InitStack()
{
    int n;
    printf("Introduceti capacitatea stivei: ");
    scanf("%d", &n);
    s = createStack(n);
}

void ReadStack()
{
    int n;
    printf("Introduceti numarul de elemente din stiva: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Imobil * c = ReadData();
        Element * e = createElement(c);
        push(s, e);
    }
}

void ExportStack()
{
    FILE * f = fopen("stiva.txt", "w");
    for (int i = 0; i <= s->top; i++)
    {
        char * str = ToString((Imobil *)s->array[i].data);
        fwrite(str, sizeof(char), strlen(str), f);
    }
    fclose(f);
}

void StackMax()
{
    Imobil * max = (Imobil *)malloc(sizeof(Imobil));
    max = (Imobil *)s->array[0].data;
    for (int i = 1; i <= s->top; i++)
    {
        if (max->cost < ((Imobil *)s->array[i].data)->cost)
        {
            max = (Imobil *)s->array[i].data;
        }
    }
    printf("Imobilul cu costul maxim este: \n");
    PrintData(max);
}

void TransferToQueue()
{
    q = createQueue(sizeof(Imobil));
    for (int i = 0; i <= s->top; i++)
    {
        data * d = (data *)malloc(sizeof(data));
        d->data = s->array[i].data;
        d->next = NULL;
        if (isEmpty(q))
        {
            q->head = q->tail = d;
        }
        else
        {
            q->tail->next = d;
            q->tail = d;
        }
        q->size++;
    }
}

void ExportQueue()
{
    FILE * f = fopen("coada.txt", "w");
    data * d = q->head;
    while (d != NULL)
    {
        char * str = ToString((Imobil *)d->data);
        fwrite(str, sizeof(char), strlen(str), f);
        d = d->next;
    }
    fclose(f);
}

void Len()
{
    printf("Lungimea stivei este: %d\n", s->top + 1);
}

void Update()
{
    int index = 0;
    printf("Introduceti indexul Imobilului ce urmeaza a fi modificat: ");
    scanf("%d", &index);
    if (index < 0 || index > s->top)
    {
        printf("Indexul introdus nu este valid\n");
        return;
    }
    UpdateData(s->array[index].data);
}

int userChose = 0;
int go = 1;

int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tCreaza stiva noua\n");
    printf("2 . \tCitire date stiva\n");
    printf("3 . \tExport date stiva\n");
    printf("4 . \tAfiseaza maxim din stiva\n");
    printf("5 . \tTransfer catre coada\n");
    printf("6 . \tExport date coada\n");
    printf("7 . \tLungime stiva\n");
    printf("8 . \tModificare element stiva\n");
    printf("9 . \tElibereaza memoria stivei\n");
    printf("10 . \tElibereaza memoria cozii\n");
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
            InitStack();
            PressAnyKey();
        } break;
        case 2:
        {
            ReadStack();
            PressAnyKey();
        }break;
        case 3:
        {
            ExportStack();
            PressAnyKey();
        }break;
        case 4:
        {
            StackMax();
            PressAnyKey();
        }break;
        case 5:
        {
            TransferToQueue();
            PressAnyKey();
        }break;
        case 6:
        {
            ExportQueue();
            PressAnyKey();
        }break;
        case 7:
        {
            Len();
            PressAnyKey();
        }break;
        case 8:
        {
            Update();
            PressAnyKey();
        }break;
        case 9:
        {
            deleteStack(s);
            PressAnyKey();
        }break;
        case 10:
        {
            destroyQueue(q);
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