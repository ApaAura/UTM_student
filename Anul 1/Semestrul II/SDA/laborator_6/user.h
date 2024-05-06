#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "struct.h"
#include "list.h"

List * lista;
void Read()
{
    if (lista==NULL)
    {
        lista = new_list();
    }
    char rs = 'y';
    do
    {
        Farmacie * f = ReadStruct();
        push_first(lista,f)?
            printf("succes\n"):
            printf("error\n");
        printf("Mai introduceti Farmacii(y/n)? : ");
        fflush(stdin);
        scanf("%c", &rs);
        rs = tolower(rs);
    } while (rs == 'y');
}
void ShowList()
{
    if (lista==NULL)
    {
        printf("Lista nula\n");
        return;
    }
    if (is_empty(lista))
    {
        printf("Lista goala");
        return;
    }
    Node * curent_node = lista->head;
    while (curent_node!=NULL)
    {
        ShowStruct(curent_node->value,curent_node->index);
        curent_node = curent_node->next;
    }
}
void Search()
{
    if (lista==NULL)
    {
        printf("Lista nula\n");
        return;
    }
    printf("Introduceti Numele farmaciei:");
    fflush(stdin);
    char mod[100];
    gets(mod);
    Node * curent_node = lista->head;
    while (curent_node!=NULL)
    {
        if (strcmp(((struct Farmacie *)(curent_node->value))->denumire, mod)==0)
        {
            ShowStruct(curent_node->value,curent_node->index);
            return;
        }
        curent_node = curent_node->next;
    }
    printf("Elementul cautat nu se afla in lista\n");
}
void SortList()
{
    struct Node * current = lista->head, 
                * index = NULL;  
    Farmacie * temp;  
    if (lista==NULL)
    {
        printf("Lista nula\n");
        return;
    }
    if (is_empty(lista))
    {
        printf("Lista goala");
        return;
    }
    while(current != NULL) 
    {  
        index = current->next;  
        while(index != NULL) 
        {  
            if(((struct Farmacie *)(current->value))->denumire[0] > 
                    ((struct Farmacie *)(index->value))->denumire[0]) 
            {  
                temp = current->value;  
                current->value = index->value;  
                index->value = temp;  
            }  
            index = index->next;  
        }  
        current = current->next;  
    }      
    printf("Lista a fost sortata cu succes in ordine alfabetica dupa numele farmaciilor\n");
}
void Update()
{
    printf("Introduceti ID-ul Farnaciei ce urmeaza a fi actualizata: ");
    int ID = 0;
    scanf("%d", &ID);
    if (ID>lista->Count-1)
    {
        printf("Ivalid index\n");
        return;
    }
        Node * curent = lista->head;
        while (curent!=NULL)
        {
            if (ID==curent->index)
            {
                break;
            }
            curent = curent->next;
        }
        ModifyStruct((Farmacie*)curent->value);
        curent = NULL;
        printf("Datele datele au fost actualziate\n");
}
void LastIndex()
{
    Node * curent = lista->head;
    while (curent->next!=NULL)
    {
        curent = curent->next;
    }
    printf("Ultimul nod se afla pe pozitia %d si are adresa in memorie: %p", curent->index,&curent);
}
void swapNodes(int x, int y)
{
    if (x == y)
        return;

    Node * prevX = NULL, *currX = lista->head;
    while (currX != NULL && currX->index != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node * prevY = NULL,* currY = lista->head;
    while (currY != NULL && currY->index != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else 
        lista->head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else 
        lista->head = currX;
    Node * temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}
void Swap()
{
    printf("dati Id-urile farmaciilor care urmeaza a fi interschimbate:\n\tb1 = ");
    int b1, b2;
    scanf("%d", &b1);
    printf("\tb2 = ");
    scanf("%d", &b2);
    swapNodes(b1,b2);
    setIndexes(lista);
    printf("Elementele au fost interschimbate cu succes\n");
}
void AddLast()
{
    Farmacie * c = ReadStruct();
    if (c==NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return;
    }
    if (lista==NULL)
    {
        lista = new_list();
    }
    push_last(lista, c);
    printf("Farmacia a fost adaugata cu succes\n");
}
void AddFirst()
{
    Farmacie * c = ReadStruct();
    if (c==NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return;
    }
    if (lista==NULL)
    {
        lista = new_list();
    }
    push_first(lista, c);
    printf("Farmacia a fost adaugata cu succes\n");
}
void Delete()
{
    printf("Introduceti ID-ul structurii ce urmeaza a fi stearsa: ");
    int ID = 0;
    scanf("%d", &ID);
    if (ID>lista->Count-1)
    {
        printf("Ivalid index\n");
        return;
    }
    deleteNthNode(lista, ID);
    printf("Farmacia a fost stearsa cu succes\n");
}

void AddAfter()
{
    printf("Introduceti ID-ul elementului dupa care urmeaza a fi adaugat un nou element: ");
    int ID = 0;
    scanf("%d", &ID);
    if (ID>lista->Count-1)
    {
        printf("Ivalid index\n");
        return;
    }
    Node * curent = lista->head;
    while (curent!=NULL)
    {
        if (ID==curent->index)
        {
            break;
        }
        curent = curent->next;
    }
    Farmacie * c = ReadStruct();
    if (c==NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return;
    }
    insertAfterNthNode(ID+1, c, lista);
    printf("Farmacia a fost adaugata cu succes\n");
}
void AddBefore()
{
    printf("Introduceti ID-ul elementului inaintea caruia urmeaza a fi adaugat un nou element: ");
    int ID = 0;
    scanf("%d", &ID);
    if (ID>lista->Count-1)
    {
        printf("Ivalid index\n");
        return;
    }
    Node * curent = lista->head;
    while (curent!=NULL)
    {
        if (ID==curent->index)
        {
            break;
        }
        curent = curent->next;
    }
    Farmacie * c = ReadStruct();
    if (c==NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return;
    }
    insertAfterNthNode(ID-1,c, lista);
    printf("Farmacia a fost adaugata cu succes\n");
}
void Export()
{
    if (lista==NULL)
    {
        printf("Lista nula\n");
        return;
    }
    if (is_empty(lista))
    {
        printf("Lista goala");
        return;
    }
    FILE * f = fopen("lista.txt", "w");
    if (f==NULL)
    {
        printf("Eroare la deschiderea fisierului\n");
        return;
    }
    Node * curent_node = lista->head;
    while (curent_node!=NULL)
    {
        fprintf(f, "%s", ToString(curent_node->value));
        curent_node = curent_node->next;
    }
    fclose(f);
    printf("Datele au fost exportate cu succes\n");
}
void Import()
{
    FILE * f = fopen("lista.txt", "r");
    if (f==NULL)
    {
        printf("Eroare la deschiderea fisierului\n");
        return;
    }
    char * str = (char *)malloc(1000);
    while (fgets(str, 1000, f)!=NULL)
    {
        Farmacie * c = FromString(str);
        push_first(lista, c);
    }
    fclose(f);
    printf("Datele au fost importate cu succes\n");
}



int userChose = 0;
int go = 1;


int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tCrearea listei in memoria dinamica\n");
    printf("2 . \tIntroducerea informatiei despre elementele listei de latastatura\n");
    printf("3 . \tAfiseaza informatia despre elementele listei la ecran\n");
    printf("4 . \tCautarea elementului in lista\n");
    printf("5 . \tModificarea campurilor unui element din lista\n");
    printf("6 . \tDeterminarea adresei ultimului element din lista\n");
    printf("7 . \tDeterminarea lungimii listei\n");
    printf("8 . \tInterschimbarea a doua elemente indicate in lista\n");
    printf("9 . \tSortarea listei\n");
    printf("10 . \tAdauga element la inceputul listei\n");
    printf("11 . \tAdauga element dupa un element indicat\n");
    printf("12 . \tAdauga element inaintea unui element idicat\n");
    printf("13 . \tStergerea elementului indicat in lista\n"); 
    printf("14 . \tExport informatii in fisier\n"); 
    printf("15 . \tImport informatii in fisier\n"); 
    printf("16 . \tEliberarea memoriei alocate pentru lista\n");
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
            lista = new_list();
            printf("Lista a fost creata cu succes");
            PressAnyKey();
        } break;
        case 2:
        {
            Read();
            PressAnyKey();
        }break;
        case 3:
        {
            ShowList();
            PressAnyKey();
        }break;
        case 4:
        {
            Search();
            PressAnyKey();
        }break;
        case 5:
        {
            Update();
            PressAnyKey();
        }break;
        case 6:
        {
            LastIndex();
            PressAnyKey();
        }break;
        case 7:
        {
            printf("Lista contine %d elemente", lista->Count);
            PressAnyKey();
        }break;
        case 8:
        {
            Swap();
            PressAnyKey();
        }break;
        case 9:
        {
            SortList();
            PressAnyKey();
        }break;
        case 10:
        {
            AddFirst();
            PressAnyKey();
        }break;
        case 11:
        {
            AddAfter();
            PressAnyKey();
        }break;
        case 12:
        {
            AddBefore();
            PressAnyKey();
        }break;
        case 13:
        {
            Delete();
            PressAnyKey();
        }break;
        case 14:
        {
            Export();
            PressAnyKey();
        }break;
        case 15:
        {
            Import();
            PressAnyKey();
        }break;
        case 16:
        {
            clear_list(lista);
            is_empty(lista)?
                printf("succes\n"):
                printf("error\n");
            delete_list(lista);
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