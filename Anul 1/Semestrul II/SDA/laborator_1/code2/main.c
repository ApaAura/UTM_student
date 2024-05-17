#include "user.h"

//Se dă un array bidimensional cu elemente de tip integer și un număr natural n (n ≥ 0), valoarea căruia este citită de la tastatură. 
//Să se afișeze array-ul original și array-ul modificat după fiecare manipulare a datelor din array, afișarea rezultatelor ca și concluzie 
//A. Dacă numărul elementelor, aflate deasupra diagonalei principale, este mai mare decât valoarea lui k, 
//declarată ca o constantă globală, atunci să se sorteze crescător elementele de pe diagonala secundară, 
//aplicând tehnica de sortare QuickSort, altfel să se sorteze descrescător elementele din prima coloană, aplicând tehnica de sortare ShellSort.
//B. Dacă elementul maxim se găsește o singură dată în array, atunci să se sorteze crescător elementele 
//liniei în care se află elementul maxim, aplicând tehnica de sortare SelectionSort, 
//altfel să se sorteze descrescător elementele de pe coloanele în care se află elementul maxim, 
//aplicând tehnica de sortare InsertionSort.



int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tIntroducerea valorilor matricii de la tastaura\n");
    printf("2 . \tComplentarea matricii cu valori random\n");
    printf("3 . \tAfisarea elementelor matricii la ecran\n");
    printf("4 . \tSortarea elementelor matricii A\n");
    printf("5 . \tSortarea elementelor matricii B\n");
    printf("0 . \tExit\n");
    printf("---------------------------------------------------------------------\nOptiunea aleasa --> ");
    int op;
    scanf("%d", &op);
    system("cls");
    return op;
}

bool go = true;
int userChose = 0;

void BL()
{
    switch (userChose)
    {
        case 1: 
        {
            ReadArray();
            printf("Array citit cu succes\n");
            PressAnyKey();
        } break;
        case 2:
        {
            RandomArray();
            printf("Array generat cu succes\n");
            printArray();
            PressAnyKey();
        }break;
        case 3:
        {
            printArray();
            PressAnyKey();
        }break;
        case 4:
        {
            TaskA();
            PressAnyKey();
        }break;
        case 5:
        {
            TaskB();
            PressAnyKey();
        }break;
        case 0:
        {
            go = false;
        }break;
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
