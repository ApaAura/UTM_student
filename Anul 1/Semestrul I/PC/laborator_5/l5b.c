#include <stdio.h>
#include <ctype.h>

void CitireSir(char str[], int max_length);
void DeterminareFrecventa(char str[], int frequency[]);
void AfisareRezultate(int frequency[]);

int main() {
    char str[100]; 
    int frequency[26] = {0}; 

    CitireSir(str, 100);
    DeterminareFrecventa(str, frequency);
    AfisareRezultate(frequency);

    return 0;
}

void CitireSir(char str[], int max_length) {
    printf("Introduceti un sir de caractere: ");
    fgets(str, max_length, stdin);
}

void DeterminareFrecventa(char str[], int frequency[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]); 
        if (ch >= 'a' && ch <= 'z') {
            frequency[ch - 'a']++; 
        }
    }
}

void AfisareRezultate(int frequency[]) {
    printf("Frecventa repetarii literelor:\n");
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }
}