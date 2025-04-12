#include <iostream>
#include "MyVector.h"

int main()
{
    int size = 5;
    MyVector MyV(size);
    MyVector MyV2(size);

    cout << "Introduceti 5 elemente ale primului vector:\n";
    cin >> MyV;

    cout << "\nIntroduceti 5 elemente ale celui de-al doilea vector:\n";
    cin >> MyV2;

    system("cls");

    cout << "Primul vector este: ";
    cout << MyV << endl;

    cout << "Al doilea vector este: ";
    cout << MyV2 << endl;

    MyVector sum = MyV + MyV2;
    cout << "Suma celor doi vectori: " << sum << endl;

    MyVector diff = MyV - MyV2;
    cout << "Diferenta celor doi vectori: " << diff << endl;

    cout << "Modulul primului vector: " << MyV.Modulus() << endl;
    cout << "Modulul celui de-al doilea vector: " << MyV2.Modulus() << endl;

    cout << "Comparatii:\n";
    cout << "V1 == V2 -> " << (MyV == MyV2) << endl;
    cout << "V1 != V2 -> " << (MyV != MyV2) << endl;
    cout << "V1 < V2  -> " << (MyV < MyV2) << endl;
    cout << "V1 > V2  -> " << (MyV > MyV2) << endl;

    return 0;
}
