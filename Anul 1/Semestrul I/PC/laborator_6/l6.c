#include <stdio.h>
#include <stdlib.h>

    int l, c;
    int ** m1, ** m2, ** m3;

    void readData(){
        printf("Introduceti numarul de linii: ");
        scanf("%d", &l);
        printf("Introduceti numarul de coloane: ");
        scanf("%d", &c);
        m1 = (int **)malloc(l * sizeof(int *));
        printf("Introduceti elementele primului tablou:\n");
        for (size_t i = 0; i < l; i++)
        {
            m1[i] = (int *)malloc(c * sizeof(int));
            for (size_t j = 0; j < c; j++)
            {
                printf("m1[%d][%d] = ", i, j);
                scanf("%d", &m1[i][j]);
            }
        }
        m2 = (int **)malloc(l * sizeof(int *));
        printf("Introduceti elementele celui de-al doilea tablou:\n");
        for (size_t i = 0; i < l; i++)
        {
            m2[i] = (int *)malloc(c * sizeof(int));
            for (size_t j = 0; j < c; j++)
            {
                printf("m2[%d][%d] = ", i, j);
                scanf("%d", &m2[i][j]);
            }
        }
    }

    void calculateSum(){
         m3 = (int **)malloc(l * sizeof(int *));
        for (size_t i = 0; i < l; i++)
        {
            m3[i] = (int *)malloc(c * sizeof(int));
            for (size_t j = 0; j < c; j++)
            {
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }

    void showData(){
        printf("Suma celor doua tablouri este:\n");
        for (size_t i = 0; i < l; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                printf("%d ", m3[i][j]);
            }
            printf("\n");
        }
    }

int main()
{
    readData();
    calculateSum();
    showData();
    
    for (size_t i = 0; i < l; i++)
    {
        free(m1[i]);
        free(m2[i]);
        free(m3[i]);
    }
    free(m1);
    free(m2);
    free(m3);
    return 0;
}