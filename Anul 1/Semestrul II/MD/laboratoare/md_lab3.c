#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

int** graph;
int** ponderedMatrix;
int** V;
int nodes = 0, edges = 0;


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
void ReadVals()
{
    printf("Numarul de nodru: ");
    scanf("%d", &nodes);
    printf("Numarul de muchii: ");
    scanf("%d", &edges);
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
            ponderedMatrix[i][j] = 999;
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
void elibMemPondered()
{
    if ((nodes != 0) && (edges != 0))
    {
        for (int i = 0; i < nodes; i++)
            free(*(ponderedMatrix + i));
        free(ponderedMatrix);
    }
}
void AllocMemForV(int nodes)
{
    V = (int**)malloc((nodes+1) * sizeof(int*));
    for (size_t i = 0; i < nodes+1; i++)
    {
        *(V + i) = (int*)malloc((nodes + 1) * sizeof(int));
    }
}
void FreeV(int nodes)
{
    for (size_t i = 0; i < nodes+1; i++)
    {
        free(*(V + i));
    }
    free(V);
}
void KalabaMin()
{
    GraphToPonderedWithMax();
    AllocMemForV(nodes);
    for (size_t i = 0; i < nodes; i++)
    {
        for (size_t j = 0; j < nodes; j++)
        {
            V[i][j] = 999;
        }
    }
    for (int j = 0; j < nodes; j++)
    {
        //v0
        V[0][j] = ponderedMatrix[j][nodes - 1];
    }
    bool go = true;
    int cicles = 1;
    do
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (((ponderedMatrix[i][j] + V[cicles - 1][j]) < (V[cicles][i])))
                {
                    V[cicles][i] = ponderedMatrix[i][j] + V[cicles - 1][j];
                }
            }
        }
        // compararea liniilor 
        for (int j = 0; j < nodes; j++)
        {
            if (V[cicles - 1][j] != V[cicles][j])
            {
                go = true;
                cicles++;
                break;
            }
            else
            {
                go = false;
            }
        }
    } while (go);
    int count = 0;
    int** AuxMatrix = (int**)malloc(nodes * sizeof(int*));
    for (size_t i = 0; i < nodes; i++)
    {
        *(AuxMatrix + i) = (int*)malloc(nodes * sizeof(int));
    }
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (((V[cicles][i] - V[cicles][j + 1]) == ponderedMatrix[i][j + 1]) && (V[cicles][i] != V[cicles][j + 1]))
            {
                AuxMatrix[i][count] = j + 2;
                count++;
            }
        }
        count = 0;
    }
    int f = 0, c = 2;
    int* DrumBelman = (int*)malloc(nodes * sizeof(int));
    DrumBelman[0] = 1;
    DrumBelman[1] = AuxMatrix[0][0];
    int poz = DrumBelman[1];
    do
    {
        DrumBelman[f + 2] = AuxMatrix[poz - 1][0];
        poz = DrumBelman[f + 2];
        f++;
        c++;
    } while (poz != nodes);

    printf("\n\nMatricea ponderata introdusa:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            printf("%4d  ", ponderedMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\nDrumul minim xi(1-%d) = %d \n ", nodes, V[cicles][0]);
    for (int i = 0; i < c; i++)
    {
        printf("%d  ", DrumBelman[i]);
    }
    //Eliberare memorie
    elibMemPondered();
    FreeV(nodes);
    free(DrumBelman);
    for (size_t i = 0; i < nodes; i++)
    {
        free(*(AuxMatrix + i));
    }
    free(AuxMatrix);
}

int userChose = 0;
int go = 1;

int ShowMenu()
{
    printf("===============Meniul Aplicatiei===============\n");
    printf("1 . \tIntroducere graf ponderat forma canonica\n");
    printf("2 . \tDrum minim intre doua noduri Bellman - Kalaba\n");
    printf("3 . \tEliberare memorie\n");
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
        KalabaMin();
        PressAnyKey();
    }break;
    case 3:
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