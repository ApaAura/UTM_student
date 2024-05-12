#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//list logic
typedef struct Node
{
    int index;
    void * value;
    struct Node * next;
}Node;

typedef struct List
{
    int Count;
    Node * head;
}List;

List * new_list()
{
    List * list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->Count=0;
    return list;
}

Node * new_node(void * data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->value = data;
    node->next = NULL;
    return node;
}

int setIndexes(List *list)
{
    int n = 0;
    Node * curent_node = list->head;
    while (curent_node!=NULL)
    {
        curent_node->index = n;
        n++;
        curent_node = curent_node->next;
    }
    return n;
}

bool push_first(List *list, void * data)
{
    Node * newNode = new_node(data);
    newNode->next = list->head;
    list->head = newNode;
    list->Count++;
    int n = setIndexes(list);
    if (n == list->Count)
    {
        return true;
    }
    return false;
}
bool push_last(List *list, void * data)
{
    struct Node *newNode = new_node(data);
    newNode->value = data;
    newNode->next = NULL;
    if(list->head == NULL)
            list = new_list();
    else
    {
        struct Node *lastNode = list->head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    list->Count++;
    int n = setIndexes(list);
    if (n == list->Count)
    {
        return true;
    }
    return false;
}
void * pop_first(List *list)
{
    Node * old_node = list->head;
    void * return_value = 0;
    if(old_node)
    {
        list->head = list->head->next;
        return_value = old_node->value;
        free(old_node);
    }
    list->Count--;
    return return_value;
}

void clear_list(List *list)
{
    Node * current_node = list->head, * back_node =NULL;
    while(current_node)
    {
        back_node = current_node;
        current_node=current_node->next;
        free(back_node);
    }
    list->head = NULL;
    list->Count = 0;
}

void delete_list(List *list)
{
    clear_list(list);
    free(list);
}

bool is_empty(List *a)
{
    return (a->head)?false:true;
}
void tailRecRevese(Node* current, Node* previous, Node** head){
    if (!current->next) 
    {
        *head = current;
        current->next = previous;
        return;
    }
    Node* next = current->next;
    current->next = previous;
    tailRecRevese(next, current, head);
}
void tailRecReveseLL(Node** head){
    if (!head)
        return;
    tailRecRevese(*head, NULL, head);
}
void reverse(List * a)
{
    tailRecReveseLL(&(a->head));
    printf("Lista a fost inversata\n");
}
void deleteNthNode(List * lista, int n)
{
    if(n < 0 || n >= lista->Count) 
        printf("pozitie de stergere invalida\n"); 
    else if(n == 0)
    {
        Node * temp = lista->head;
        lista->head = lista->head->next;
        free(temp);
        lista->Count--;
    }
    else 
    {
        Node * temp = lista->head;
        while(--n)
        {
            temp=temp->next;
        }
        Node * temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        lista->Count--;
    }
    int x = setIndexes(lista);
    if (x == lista->Count)
    {
        printf("Nodul a fost sters\n");
    }
}
bool insertAfterNthNode(int n, void * data, List * lista)
{
    struct Node* newNode = new_node(data); 
    if(n < 0 || n > lista->Count) 
        printf("pozitie de inserare invalida\n"); 
    else if(n == 0)
    {
        newNode->next = lista->head; 
        lista->head = newNode;
        lista->Count++;
    }
    else 
    {
        struct Node* temp = lista->head; 
        while(--n)
        {
            temp=temp->next;
        }
        newNode->next= temp->next;
        temp->next = newNode;
        lista->Count++;
    }
    int x = setIndexes(lista);
    if (x == lista->Count)
    {
        return true;
    }
    return false;
}