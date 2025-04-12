#pragma once
#include "Mobila.h"
class Scaun : public Mobila
{
	private:
		double GreutateAdmisa;
		string MaterialCarcasa;
		string Culoare;
	public:
		Scaun() :Mobila(0,"Undefined", Other)
		{
			GreutateAdmisa = 0;
			MaterialCarcasa = "";
			Culoare = "";
		}
		Scaun(string nume, double pret, double greutateAdmisa, string materialCarcasa, string culoare, FurnitureType type) : Mobila(pret, nume, type)
		{
			GreutateAdmisa = greutateAdmisa;
			MaterialCarcasa = materialCarcasa;
			Culoare = culoare;
		}
		//getters
		double GetGreutateAdmisa() { return GreutateAdmisa; }
		string GetMaterialCarcasa() { return MaterialCarcasa; }
		string GetCuloare() { return Culoare; }
		//setters
		void SetGreutateAdmisa(double greutateAdmisa) { GreutateAdmisa = greutateAdmisa; }
		void SetMaterialCarcasa(string materialCarcasa) { MaterialCarcasa = materialCarcasa; }
		void SetCuloare(string culoare) { Culoare = culoare; }
		string ToString()
		{
			string result = Mobila::ToString();
			result += "Greutate admisa: " + to_string(GreutateAdmisa) + "\n";
			result += "Material carcasa: " + MaterialCarcasa + "\n";
			result += "Culoare: " + Culoare + "\n";
			return result;
		}
		void Read() override
		{
			Mobila::Read();
			cout << "Greutate maxima admisa: ";
			cin >> GreutateAdmisa;
			cout << "Material carcasa: ";
			cin >> MaterialCarcasa;
			cout << "Culoare: ";
			cin >> Culoare;
		}
};

