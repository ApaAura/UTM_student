#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Numarul de elemente: ");
    scanf("%d", &n);
    printf("Introduceti elementele: ");
    float * mas = malloc(n * sizeof(float)); 
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &mas[i]);
    }
    int count = 0;
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(mas[i] < 0)
        {
            count++;
        }
        sum += mas[i];
    }
    printf("Numarul de elemente negative: %d\n", count);
    printf("Suma elementelor: %.3f\n", sum);
    free(mas); 
    return 0;
}