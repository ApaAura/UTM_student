#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define MAX 100
#define K 100 //change this to check the task A condition
                //for task B you can generate the array multiple times to get the conditions
int Rows = 10;
int Cols = 10;
int Array[MAX][MAX];

void printArray() {
    printf("Elementele matricii: \n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%d ", Array[i][j]);
        }
        printf("\n");
    }
}

void ReadArray()
{
    printf("Introduceti numarul de linii al matricii:");
    scanf("%d", &Rows);
    printf("Introduceti numarul de coloane al matricii:");
    scanf("%d", &Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("Array[%d][%d]=", i, j);
            scanf("%d", &Array[i][j]);
        }
    }
}

void RandomArray()
{
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            Array[i][j] = rand() % 100;
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int CountAboveMainDiagonal()
{
    int count = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i < j) {
                count++;
            }
        }
    }
    return count;
}

//-------------QuickSort----------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//-------------QuickSort----------------

//-------------ShellSort----------------
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
//-------------ShellSort----------------
void TaskA()
{
    int * tempArr = (int *)malloc(Rows * sizeof(int));
    if(CountAboveMainDiagonal()>K)
    {
        printf("Numarul de elemente deasupra diagonalei principale este mai mare decat %d\nEmelentele diagonalei secundare vor fi sortate crescator prin Quick Sort", K);
        printf("\nDiagonala secundara este: ");
        for (int i = 0; i < Rows; i++) {
            printf("%d ", Array[i][Cols - i - 1]);
            tempArr[i] = Array[i][Cols - i - 1];
        }
        quickSort(tempArr, 0, Rows - 1);
        printf("\nDiagonala secundara sortata este: ");
        for (int i = 0; i < Rows; i++) {
            printf("%d ", tempArr[i]);
        }
        for (int i = 0; i < Rows; i++) {
            Array[i][Cols - i - 1] = tempArr[i];
        }
    }
    else
    {
        printf("Numarul de elemente deasupra diagonalei principale este mai mic sau egal cu %d\nColoana 1 va fi sortata descrescator prin Shell Sort", K);
        printf("\nColoana 1 este: ");
        for (int i = 0; i < Rows; i++) {
            printf("%d ", Array[i][0]);
            tempArr[i] = Array[i][0];
        }
        shellSort(tempArr, Rows);
        printf("\nColoana 1 sortata este: ");
        for (int i = 0; i < Rows; i++) {
            printf("%d ", Array[i][0]);
            Array[i][0] = tempArr[i];
        }
    }
    printf("\nArray-ul modificat este: \n");
    printArray();
    free(tempArr);
}

int Max()
{
    int max = Array[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array[i][j] > max) {
                max = Array[i][j];
            }
        }
    }
    return max;
}

int CountMax()
{
    int count = 0;
    int max = Max();
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array[i][j] == max) {
                count++;
            }
        }
    }
    return count;
}

int MaxLineIndex()
{
    int max = Max();
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array[i][j] == max) {
                return i;
            }
        }
    }
    return -1;
}
//-------------SelectionSort----------------
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
//-------------SelectionSort----------------
int * maxCollumn()
{
    //returns a array of 0 and 1, 1 if the collumn has the max element
    int max = Max();
    int* returns = (int*)malloc(Cols * sizeof(int));
    for (int i = 0; i < Cols; i++) {
        returns[i] = 0;
    }
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Array[i][j] == max) {
                returns[j] = 1;
            }
        }
    }
    return returns;
}

//-------------InsertionSort----------------
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//-------------InsertionSort----------------

void TaskB()
{
    if (CountMax()==1)
    {
        int lineIndex = MaxLineIndex();
        printf("Elementul maxim se gaseste o singura data in array\nRandul %d va fi sortat crescator prin Selection Sort",lineIndex);
        int* tempArr = (int*)malloc(Cols * sizeof(int));
        printf("\nRandul inital: ");
        for (int i = 0; i < Cols; i++) {
            printf("%d ", Array[lineIndex][i]);
            tempArr[i] = Array[lineIndex][i];
        }
        SelectionSort(tempArr, Cols);
        printf("\nRandul %d sortat este: ", lineIndex);
        for (int i = 0; i < Cols; i++) {
            printf("%d ", tempArr[i]);
            Array[lineIndex][i] = tempArr[i];
        }
        free(tempArr);
    }
    else
    {
        int* collumns = maxCollumn();
        printf("Elementul maxim se gaseste de mai multe ori in array\nColoanele in care se gaseste elementul maxim vor fi sortate descrescator prin Insertion Sort");
        for (int i = 0; i < Cols; i++) {
            if (collumns[i] == 1) {
                int* tempArr = (int*)malloc(Rows * sizeof(int));
                printf("\nColoana %d initala: ", i);
                for (int j = 0; j < Rows; j++) {
                    printf("%d ", Array[j][i]);
                    tempArr[j] = Array[j][i];
                }
                InsertionSort(tempArr, Rows);
                printf("\nColoana %d sortata este: ", i);
                for (int j = 0; j < Rows; j++) {
                    printf("%d ", tempArr[j]);
                    Array[j][i] = tempArr[j];
                }
                free(tempArr);
            }
        }
    }
    printf("\nArray-ul modificat este: \n");
    printArray();
}

void PressAnyKey()
{
    printf("\nAtingeti o tasta pentru a continua\n");
    getch();
    system("cls");
}