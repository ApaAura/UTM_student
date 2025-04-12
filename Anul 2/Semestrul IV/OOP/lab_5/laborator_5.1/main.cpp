#include "Matrix.h"

int main()
{
	Matrix MyMat(3);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			MyMat.set(i, j, i + j);
		}
	}
	int rows, columns;
	cout << "Introduceti numarul de linii ale matricei: ";
	cin >> rows;
	cout << "Introduceti numarul coloane ale matricei: ";
	cin >> columns;
	Matrix MyMat2(rows, columns);
	cout << "Introduceti elementele matricei: ";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			double element;
			cout << "mat[" << i << "][" << j << "]=";
			cin >> element;
			MyMat2.set(i, j, element);
		}
	}
	system("cls");
	cout << "Matricea 1: " << endl;
	MyMat.print();
	cout << "Matricea 2: " << endl;
	MyMat2.print();
	try
	{
		Matrix MyMat3 = (MyMat + MyMat2) * 1.5f;
		cout << "Matricea 3((m1+m2)*1.5): " << endl;
		MyMat3.print();
		Matrix prod = MyMat * MyMat3;
		cout << "Matricea 4 (m1*m3): " << endl;
		prod.print();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}