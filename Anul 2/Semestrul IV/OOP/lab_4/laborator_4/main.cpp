#include "ArithmeticProgression.h"
#include "GeometricProgression.h"

int main()
{
	ArithmeticProgression ap(1, 2);
	GeometricProgression gp(1, 2);
	cout << "Termenul 5 din progresia aritmetica este: " << ap.GetNthTerm(5) << endl;
	cout << "Termenul 5 din progresia geometrica este: " << gp.GetNthTerm(5) << endl;
	cout << "Suma primelor 10 elemente ale progresiei aritmetice: " << ap.Sum(10) << endl;
	cout << "Suma primelor 10 elemente ale progresiei geometrice: " << gp.Sum(10) << endl;
}