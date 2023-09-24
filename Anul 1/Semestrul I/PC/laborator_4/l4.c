#include <stdio.h>
#include <stdlib.h>

int r, c;
int **mat;

void readData(){
    printf("Numarul de linii: ");
    scanf("%d", &r);
    printf("Numarul de coloane: ");
    scanf("%d", &c);
    mat = malloc(r * sizeof(int *)); 
    for(int i = 0; i < r; i++)
    {
        mat[i] = malloc(c * sizeof(int)); 
        for (int j = 0; j < c; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void showData(){
     printf("Matricea:\n");
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    readData();
    showData();
    int sum = 0;
    int prod = 1;
    int col = -1;
    do
    {
        printf("Coloana: ");
        scanf("%d", &col);
    } while (col < 0 || col >= c);
    for(int i = 0; i < r; i++)
    {
        if(mat[i][col] > 0 && mat[i][col] % 2 == 1)
        {
            sum += mat[i][col];
            prod *= mat[i][col];
        }
    }
    printf("Suma elementelor pozitive impare de pe coloana %d: %d\n", col, sum);
    printf("Produsul elementelor pozitive impare de pe coloana %d: %d\n", col, prod);
    for(int i = 0; i < r; i++)
    {
        free(mat[i]); 
    }
    free(mat); 
}