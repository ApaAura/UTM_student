
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int** graph;
int nodes=0, edges = 0;

int **adiacenta;
int **incidenta;
int **lista;


void ReadVals()
{
    printf("Numarul de noduri: ");
    scanf("%d", &nodes);
    printf("Numarul de muchii: ");
    scanf("%d", &edges);
}
void freeGraph()
{
    if ((nodes!=0)&&(edges!=0))
    {
        for(int i=0; i<edges; i++)
            free(*(graph + i));
        free(graph);
        nodes = 0;
        edges = 0;
    }
}
void AllocGraph()
{
    graph = (int**)malloc(edges*sizeof(int*));
    for (size_t i = 0; i < edges; i++)
    {
        *(graph + i) = (int *)malloc(2 * sizeof(int));
    }
}
void ReadGraph()
{
    if (edges!=0)
    {
        freeGraph();
    }
    ReadVals();
    AllocGraph();
    for (size_t i = 0; i < edges; i++)
    {
        printf("Muchia %d:\n\t\tstart: ", i+1);
        scanf("%d", &graph[i][0]);
        printf("\t\tend: ");
        scanf("%d", &graph[i][1]);
    }
}
void freeAd()
{
    if ((nodes!=0)&&(edges!=0))
    {
        for(int i=0; i<nodes; i++)
            free(*(adiacenta + i));
        free(adiacenta);
    }
}
void AllocAd()
{
    adiacenta = (int**)malloc(nodes*sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(adiacenta + i) = (int *)malloc(nodes * sizeof(int));
    }
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            adiacenta[i][j] = 0;
        }
    }
}
void AdiToGraph()
{
    AllocGraph();
    int foundEdges = 0;
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            if (adiacenta[i][j]==1)
            {
                graph[foundEdges][0] = i+1;
                graph[foundEdges][1] = j+1;
                foundEdges++;
            }
        }
    }
}
void FromGraphToAdi()
{
    AllocAd();
    for (size_t i = 0; i < edges; i++)
    {
        adiacenta[graph[i][0]-1][graph[i][1]-1] = 1;
    }
}
void ShowAd()
{
    printf("Matricea de adiacenta:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            printf("%d ", adiacenta[i][j]);
        }
        printf("\n");
    }
    freeAd();
}
void ReadAdiacenta()
{
    if (edges!=0)
    {
        freeAd();
    }
    ReadVals();
    AllocAd();
    printf("Introduceti matricea de adiacenta:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            printf("ad[%d][%d] = ", i, j);
            scanf("%d", &adiacenta[i][j]);
        }
    }
    AdiToGraph();
    freeAd();
}
void freeIn()
{
    if ((nodes!=0)&&(edges!=0))
    {
        for(int i=0; i<nodes; i++)
            free(*(incidenta + i));
        free(incidenta);
    }
}
void AllocIn()
{
    incidenta = (int**)malloc(nodes*sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(incidenta + i) = (int *)malloc(edges * sizeof(int));
    }
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            incidenta[i][j] = 0;
        }
    }
}
void IncToGraph()
{
    AllocGraph();
    int foundEdges = 0, startNode=0,endNode=0;
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            if (incidenta[i][j]==-1)
            {
                startNode = i;
                for (size_t x = 0; x < nodes; x++)
                    if (incidenta[x][j]==1)
                    {
                        endNode = x;
                        break;
                    }
                    
                graph[j][0] = startNode+1;
                graph[j][1] = endNode+1;
            }
            startNode = 0; endNode = 0;
        }
    }
}
void FromGraphToIn()
{
    AllocIn();
    for (size_t i = 0; i < edges; i++)
    {
        incidenta[graph[i][0]-1][i] = -1;
        incidenta[graph[i][1]-1][i] = 1;
    }
}
void ShowIn()
{
    printf("Matricea de incidenta:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            printf("%d ", incidenta[i][j]);
        }
        printf("\n");
    }
    freeIn();
}
void ReadIncidenta()
{
    if (edges!=0)
    {
        freeIn();
    }
    ReadVals();
    AllocIn();
    printf("Introduceti matricea de incidenta in forma nodes\\edges:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            printf("in[%d][%d] = ", i, j);
            scanf("%d", &incidenta[i][j]);
        }
    }
    IncToGraph();
    freeIn();
}
void freeList()
{
    if ((nodes!=0)&&(edges!=0))
    {
            for(int i=0; i<nodes; i++)
            free(*(lista + i));
        free(lista);
    }
}
void AllocList()
{
    lista = (int**)malloc(nodes*sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(lista + i) = (int *)malloc(edges * sizeof(int));
    }
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            lista[i][j] = 0;
        }
    }
}
void ListToGraph()
{
    AllocGraph();
    int foundEdges = 0;
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < edges; j++)
        {
            if (lista[i][j]==0)
                break;

            graph[foundEdges][0] = i+1;
            graph[foundEdges][1] = lista[i][j];
            foundEdges++;
        }
    }
}
void FromGraphToList()
{
    AllocList();
    int* linieElemente = (int *)malloc(nodes * sizeof(int));
    for (size_t i = 0; i < nodes; i++)
    {
        linieElemente[i] = 0;
    }
    for (size_t i = 0; i < edges; i++)
    {
        lista[graph[i][0]-1][linieElemente[graph[i][0] - 1]] = graph[i][1];
        linieElemente[graph[i][0] - 1]++;
    }
    free(linieElemente);
}
void ShowList()
{
    printf("Lista de adiacenta:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        printf("%d | ", i+1);
        for (size_t j = 0; j < edges; j++)
        {
            if(lista[i][j]==0)
            {
                printf("%d\n", lista[i][j]);
                break;
            }
            printf("%d ", lista[i][j]);
        }
    }
    freeList();
}
void ReadList()
{
    if (edges!=0)
    {
        freeList();
    }
    ReadVals();
    AllocList();
    printf("Introduceti lista de adiacenta:\n");
    for (size_t i = 0; i < nodes; i++)
    {
        printf("Linia [%d]:\n",i+1);
        for (size_t j = 0; j < edges; j++)
        {
            printf("\tlist[%d][%d] = ", i+1, j);
            scanf("%d", &lista[i][j]);
            if (lista[i][j]==0)
                break;
        }
    } 
    ListToGraph();
    freeList();
}

int userChose = 0;
int go = 1;

int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tIntroducere graf forma canonica\n");
    printf("2 . \tIntroducere graf forma matrice adiacenta\n");
    printf("3 . \tIntroducere graf forma matrice incidenta\n");
    printf("4 . \tIntroducere graf forma lista adiacenta\n");
    printf("5 . \tAfisare matrice adiacenta\n");
    printf("6 . \tAfisare matrice incidenta\n");
    printf("7 . \tAfisare lista adiacenta\n");
    printf("8 . \tEliberare memorie\n");
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
            ReadGraph();
            PressAnyKey();
        } break;
        case 2:
        {
            ReadAdiacenta();
            PressAnyKey();
        }break;
        case 3:
        {
            ReadIncidenta();
            PressAnyKey();
        }break;
        case 4:
        {
            ReadList();
            PressAnyKey();
        }break;
        case 5:
        {
            FromGraphToAdi();
            ShowAd();
            PressAnyKey();
        }break;
        case 6:
        {
            FromGraphToIn();
            ShowIn();
            PressAnyKey();
        }break;
        case 7:
        {
            FromGraphToList();
            ShowList();
            PressAnyKey();
        }break;
        case 8:
        {
            freeGraph();
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
int main()
{
    system("cls");
    while (go)
    {
        userChose = Menu();
        BL();
    }
    return 0;
}