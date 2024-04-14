#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

int** graph;
int** ponderedMatrix;
int nodes = 0, edges = 0;

void ReadVals()
{
    printf("Numarul de nodru: ");
    scanf("%d", &nodes);
    printf("Numarul de muchii: ");
    scanf("%d", &edges);
}
void ElibMemGraph()
{
    if ((nodes != 0) && (edges != 0))
    {
        for (int i = 0; i < edges; i++)
            free(*(graph + i));
        free(graph);
        nodes = 0;
        edges = 0;
    }
}
void AlocMemGraph()
{
    graph = (int**)malloc(edges * sizeof(int*));
    for (size_t i = 0; i < edges; i++)
    {
        *(graph + i) = (int*)malloc(3 * sizeof(int));
    }
}
void CitireGraph()
{
    if (edges != 0)
    {
        ElibMemGraph();
    }
    ReadVals();
    AlocMemGraph();
    for (size_t i = 0; i < edges; i++)
    {
        printf("Muchia %d:\n\t\tstart: ", i + 1);
        scanf("%d", &graph[i][0]);
        printf("\t\tend: ");
        scanf("%d", &graph[i][1]);
        printf("\t\tpondere: ");
        scanf("%d", &graph[i][2]);
    }
}
void GraphToPonderedWithMax()
{
    ponderedMatrix = (int**)malloc(nodes * sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(ponderedMatrix + i) = (int*)malloc(nodes * sizeof(int));
    }
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            ponderedMatrix[i][j] = INT_MAX;
        }
    }
    for (size_t i = 0; i < nodes; i++)
    {
        ponderedMatrix[i][i] = 0;
    }
    
    for (size_t i = 0; i < edges; i++)
    {
        ponderedMatrix[graph[i][0] - 1][graph[i][1] - 1] = graph[i][2];
    }
}
void GraphToPonderedWithMin()
{
    ponderedMatrix = (int**)malloc(nodes * sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(ponderedMatrix + i) = (int*)malloc(nodes * sizeof(int));
    }
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            ponderedMatrix[i][j] = INT_MIN;
        }
    }
    for (size_t i = 0; i < edges; i++)
    {
        ponderedMatrix[graph[i][0] - 1][graph[i][1] - 1] = graph[i][2];
    }
}
void elibMemPondered()
{
    if ((nodes != 0) && (edges != 0))
    {
        for (int i = 0; i < nodes; i++)
            free(*(ponderedMatrix + i));
        free(ponderedMatrix);
    }
}
void FordLong(int start, int end)
{
    int* dist = (int*)malloc(nodes * sizeof(int));
    int* prev = (int*)malloc(nodes * sizeof(int));
    GraphToPonderedWithMin();
    for (size_t i = 0; i < nodes; i++)
    {
        dist[i] = INT_MIN;
        prev[i] = -1;
    }
    dist[start - 1] = 0;
    for (size_t i = 0; i < nodes - 1; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            for (size_t k = 0; k < nodes; k++)
            {
                if (ponderedMatrix[j][k] != INT_MIN)
                {
                    if (dist[j] != INT_MIN && dist[j] + ponderedMatrix[j][k] > dist[k])
                    {
                        dist[k] = dist[j] + ponderedMatrix[j][k];
                        prev[k] = j;
                    }
                }
            }
        }
    }
    printf("\n\nDistanta maxima de la nodul %d la nodul %d este: %d\n", start, end, dist[end - 1]);
    printf("Drumul maxim de la nodul %d la nodul %d\n", start, end);
    int current = end - 1;
    while (current != start - 1)
    {
        printf("%d ", current + 1);
        current = prev[current];
    }
    printf("%d\n", start);
    free(dist);
    free(prev);
    elibMemPondered();
}
void FordShort(int start, int end)
{
    int* dist = (int*)malloc(nodes * sizeof(int));
    int* prev = (int*)malloc(nodes * sizeof(int));
    GraphToPonderedWithMax();
    for (size_t i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[start - 1] = 0;
    for (size_t i = 0; i < nodes - 1; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            for (size_t k = 0; k < nodes; k++)
            {
                if (ponderedMatrix[j][k] != INT_MAX)
                {
                    if (dist[j] != INT_MAX && dist[j] + ponderedMatrix[j][k] < dist[k])
                    {
                        dist[k] = dist[j] + ponderedMatrix[j][k];
                        prev[k] = j;
                    }
                }
            }
        }
    }
    printf("\n\nDistanta minima de la nodul %d la nodul %d este: %d\n", start, end, dist[end - 1]);
    printf("Drumul minim de la nodul %d la nodul %d\n", start, end);
    int current = end - 1;
    while (current != start - 1)
    {
        printf("%d ", current + 1);
        current = prev[current];
    }
    printf("%d\n", start);
    free(dist);
    free(prev);
    elibMemPondered();
}


int userChose = 0;
int go = 1;

int ShowMenu()
{
    printf("===============Meniul Aplicatiei===============\n");
    printf("1 . \tIntroducere graf ponderat forma canonica\n");
    printf("2 . \tDrum minim intre doua noduri Ford\n");
    printf("3 . \tDrum maxim intre doua noduri Ford\n");
    printf("4 . \tEliberare memorie\n");
    printf("0 . \tExit\n");
    printf("===============================================\nOptiunea aleasa --> ");
    int op;
    scanf("%d", &op);
    system("cls");
    return op;
}
void PressAnyKey()
{
    printf("\nAtingeti o tasta pentru a continua\n");
    _getch();
    system("cls");
}
void MainLogic()
{
    switch (userChose)
    {
    case 1:
    {
        CitireGraph();
        PressAnyKey();
    } break;
    case 2:
    {
        int start, end;
        printf("\nIntroduceti nodul de plecare: ");
        scanf("%d", &start);
        printf("\nIntroduceti nodul de sosire: ");
        scanf("%d", &end);
        FordShort(start, end);
        PressAnyKey();
    }break;
    case 3:
    {
        int start, end;
        printf("\nIntroduceti nodul de plecare: ");
        scanf("%d", &start);
        printf("\nIntroduceti nodul de sosire: ");
        scanf("%d", &end);
        FordLong(start, end);
        PressAnyKey();
    }break;
    case 4:
    {
        ElibMemGraph();
        PressAnyKey();
    }break;
    case 0:
    {
        go = 0;
        system("cls");
        printf("Aplicatia s-a oprit cu succes");
        _getch();
    }break;
    default:printf("Optiune necunoscuta\nIncercati din nou"); break;
    }
}
int main()
{
    system("cls");
    while (go)
    {
        userChose = ShowMenu();
        MainLogic();
    }
    return 0;
}