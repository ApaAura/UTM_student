#include <iostream>

using namespace std;

long long fibRec(int a) //recursiva
{
	if (a == 0)
		return 0;
	if (a == 1)
		return 1;
	return fibRec(a - 1) + fibRec(a - 2);
}

long long fibIt(int a) //iterativa
{
	long long f1 = 0;
	long long f2 = 1;
	long long f3 = 1;
	for (int i = 0; i < a; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f1;
}

long long fibDir(int a)
{
	return (1 / sqrt(5))*(pow(((1+sqrt(5)) / 2), a) - (pow(((1 - sqrt(5)) / 2), a)));
}

int main()
{
	cout <<"Recursiva:\t" << fibRec(7) << endl;
	cout <<"Iterativa:\t" << fibIt(7) << endl;
	cout <<"Formula:\t" << fibDir(7) << endl;
	
	return 0;
}