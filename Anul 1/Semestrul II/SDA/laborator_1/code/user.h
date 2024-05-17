#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>

int userChose = 0;
int go = 1;

//1. Introducerea valorilor tabloului de la tastatură;
//2. Completarea tabloului cu valori random;
//3. Afișarea elementelor tabloului la ecran;
//4. Sortarea elementelor tabloului conform variantelor;
//5. Eliberarea memoriei și ieșirea din program


//Se dă un array unidimensional cu elemente de tip integer și un număr natural n, valoarea căruia 
//este citită de la tastatură. Să se afișeze array-ul original și array-ul modificat după fiecare manipulare 
//a datelor din array, afișarea rezultatelor ca și concluzie (De ex.: Nu există numere prime; 
//Nu există așa element cu indexul dat și alte date stipulate în condiția problemei) etc.
    //A. Dacă media aritmetică a elementelor de pe poziții pare este mai mare decât media aritmetică a elementelor 
        //de pe pozițiile impare, atunci să se sorteze elementele array-ului crescător, aplicând tehnica de sortare HeapSort, 
        //altfel să se sorteze elementele array-ului descrescător, aplicând tehnica de sortare CountingSort.
    //B. Dacă există numere prime în array, atunci să se sorteze elementele array-ului crescător, aplicând tehnica 
        //de sortare RadixSort, altfel să se sorteze elementele array-ului descrescător, aplicând tehnica de sortare CombSort.
    //C. Dacă produsul elementelor negative este un număr negativ (array va conține atât elemente pozitive, 
        //cât și elemente negative), atunci să se sorteze elementele arrayului descrescător, aplicând tehnica de sortare MergeSort, 
        //altfel să se sorteze elementele array-ului crescător, aplicând tehnica de sortare BubbleSort.


int * arr;
int * arr2;
int count = 0;

void Read()
{
    printf("Introduceti numarul de elemente din tablou: ");
    scanf("%d", &count);
    arr = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        printf("Introduceti elementul %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void Random()
{
    printf("Introduceti numarul de elemente din tablou: ");
    scanf("%d", &count);
    arr = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        arr[i] = (rand() % 100)-50;
    }
}

void Print(int * arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

float Avg(int odd)
{
    float sum = 0;
    int c = 0;
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == odd) //0 - even(par), 1 - odd (imp)
        {
            sum += arr[i];
            c++;
        }
    }
    return sum/c;
}

void swap(int * a, int * b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

//-------------HeapSort----------------
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
//-------------HeapSort----------------

//-------------CountingSort---------------- 
int Max(int * arr, int count)
{
    int max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[], int n) 
{ 
    int k = Max(arr, n); 
    int * count = (int*)malloc((k + 1) * sizeof(int));
    for (int i = 0; i < n; i++) { 
        count[arr[i]]++; 
    } 
    for (int i = k - 1; i >= k; i--) { 
        count[i] = count[i] + count[i + 1]; 
    } 
    int * ans = (int*)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) { 
        ans[--count[arr[i]]] = arr[i]; 
    } 
    for (int i = 0; i < n; i++) { 
        arr[i] = ans[i]; 
    } 
    free(count);
    free(ans);
} 
//-------------CountingSort----------------

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool hasPrime()
{
    for (int i = 0; i < count; i++)
    {
        if (isPrime(arr[i]))
        {
            return true;
        }
    }
    return false;
}

//-------------RadixSort----------------
void RadixSort(int * arr, int count)
{
    int max = Max(arr, count);
    int *output = (int *)malloc(count * sizeof(int));
    int exp = 1;

    while (max / exp > 0) {
        int count_digits[10] = {0};

        for (int i = 0; i < count; i++)
            count_digits[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count_digits[i] += count_digits[i - 1];

        for (int i = count - 1; i >= 0; i--) {
            output[count_digits[(arr[i] / exp) % 10] - 1] = arr[i];
            count_digits[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < count; i++)
            arr[i] = output[i];

        exp *= 10;
    }

    free(output);
}
//-------------RadixSort----------------

//-------------CombSort----------------
void CombSort(int arr[], int count)
{
    float shrink = 1.3;
    int gap = count;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = (int)(gap / shrink);
        if (gap < 1)
        {
            gap = 1;
        }
        int i = 0;
        swapped = false;
        while (i + gap < count)
        {
            if (arr[i] < arr[i + gap])
            {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
            i++;
        }
    }
}
//-------------CombSort----------------

bool hasNegative()
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < 0)
        {
            return true;
        }
    }
    return false;
}
int negProd()
{
    int prod = 1;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < 0)
        {
            prod *= arr[i];
        }
    }
    return prod;
}
//----------------MergeSort----------------
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int * L = malloc(sizeof(int) * n1);
    int * R = malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { // Change here
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
//----------------MergeSort----------------

//-------------BubbleSort----------------
void bubbleSort(int arr[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
//-------------BubbleSort----------------


int Menu()
{
    printf("-------------------------Meniul Aplicatiei-------------------------\n");
    printf("1 . \tIntroducerea valorilor tabloului de la tastatura\n");
    printf("2 . \tCompletarea tabloului cu valori random\n");
    printf("3 . \tAfisarea elementelor tabloului la ecran\n");
    printf("4 . \tSortarea elementelor tabloului A\n");
    printf("5 . \tSortarea elementelor tabloului B\n");
    printf("6 . \tSortarea elementelor tabloului C\n");
    printf("7 . \tEliberarea memoriei\n");
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
            Read();
            PressAnyKey();
        } break;
        case 2:
        {
            Random();
            PressAnyKey();
        }break;
        case 3:
        {
            printf("Elementele tabloului:\n");
            Print(arr, count);
            PressAnyKey();
        }break;
        case 4:
        {
            float even = Avg(0);
            float odd = Avg(1);
            printf("Media elementelor de pe pozitii pare = %d\n", even);
            printf("Media elementelor de pe pozitii impare = %d\n", odd);
            if (even > odd)
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf(" asc HeapSort\n");
                heapSort(arr2, count);
            }
            else
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf("desc CountingSort\n");
                count_sort(arr2, count);
            }
            Print(arr2, count);
            PressAnyKey();
            free(arr2);
        }break;
        case 5:
        {
            if (hasPrime())
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf("Array-ul contine numere prime !\n");
                printf(" asc RadixSort\n");
                RadixSort(arr2, count);
            }
            else
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf("Array-ul nu contine numere prime !\n");
                printf("desc CombSort\n");
                CombSort(arr2, count);
            }
            Print(arr2, count);
            PressAnyKey();
            free(arr2);
        }break;
        case 6:
        {
            printf("Produsul elementelor negative:  %d\n",negProd());
            if (negProd() < 0)
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf("desc MergeSort\n");
                mergeSort(arr2, 0, count - 1);
            }
            else
            {
                arr2 = (int*)malloc(count * sizeof(int));
                for (int i = 0; i < count; i++)
                {
                    arr2[i] = arr[i];
                }
                printf("asc BubbleSort\n");
                bubbleSort(arr2, count);
            }
            Print(arr2, count);
            PressAnyKey();
            free(arr2);
        }break;
        case 7:
        {
            free(arr);
            PressAnyKey();
        }break;
        case 0:
        {
            go=0;
            system("cls");
            printf("Aplicatia s-a oprit cu succes");
            getch();
        }break;
        default:
        {
            printf("Optiune necunoscuta\nIncercati din nou");
        }break;
    }
}