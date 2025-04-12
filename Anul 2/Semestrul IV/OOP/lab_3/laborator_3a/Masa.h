#pragma once
#include "Mobila.h"

class Masa : public Mobila
{
	private:
		double Inaltime;
		double Greutate;
		string Material;
	public:
		Masa() :Mobila(0, "Undefined", Other)
		{
			Inaltime = 0;
			Greutate = 0;
			Material = "";
		}
		Masa(string nume, double pret, double inaltime, double greutate, string material, FurnitureType type) : Mobila(pret, nume, type)
		{
			Inaltime = inaltime;
			Greutate = greutate;
			Material = material;
		}
		//getters
		double GetInaltime() { return Inaltime; }
		double GetGreutate() { return Greutate; }
		string GetMaterial() { return Material; }
		//setters
		void SetInaltime(double inaltime) { Inaltime = inaltime; }
		void SetGreutate(double greutate) { Greutate = greutate; }
		void SetMaterial(string material) { Material = material; }
		string ToString()
		{
			string result = Mobila::ToString();
			result += "Inaltime: " + to_string(Inaltime) + "\n";
			result += "Greutate: " + to_string(Greutate) + "\n";
			result += "Material: " + Material + "\n";
			return result;
		}
		void Read() override
		{
			Mobila::Read();
			cout << "Inaltime: ";
			cin >> Inaltime;
			cout << "Greutate: ";
			cin >> Greutate;
			cout << "Material: ";
			cin >> Material;
		}
};

