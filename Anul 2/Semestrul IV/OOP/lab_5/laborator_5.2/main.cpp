#include <iostream>

template <typename T>
void schimbaPerechi(T arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        T suma = arr[i] + arr[i + 1];
        T diferenta = arr[i] - arr[i + 1];
        arr[i] = suma;
        arr[i + 1] = diferenta;
    }
}

template <typename T>
void afisareTablou(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {0, 2, 3, 4, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tablou initial: ";
    afisareTablou(arr, size);

    schimbaPerechi(arr, size);

    std::cout << "Tablou modificat: ";
    afisareTablou(arr, size);

    return 0;
}