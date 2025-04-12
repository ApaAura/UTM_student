#include "Scaun.h"
#include "Masa.h"

int main()
{
	Scaun * s1 = new Scaun();
	Masa * m1 = new Masa();
	cout << "Introduceti datele scaunului: " << endl;
	s1->Read();
	cout << "Introduceti datele mesei:   " << endl;
	m1->Read();
	system("cls");
	cout << "Datele scaunului:   " << endl;
	cout<<s1->ToString()<<endl;
	cout << "Datele mesei:   " << endl;
	cout << m1->ToString() << endl;
	return 0;
}
