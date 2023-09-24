#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * str = malloc(100 * sizeof(char));
    printf("Introduceti un string: ");
    fgets(str, 100, stdin);
    int * freq = calloc(26, sizeof(int));
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            freq[str[i] - 'a']++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            freq[str[i] - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
        {
            printf("%c apare de %d ori\n", i + 'a', freq[i]);
        }
    }
    free(str);
    free(freq);
}