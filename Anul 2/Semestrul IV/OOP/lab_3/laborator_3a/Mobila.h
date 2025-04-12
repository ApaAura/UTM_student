#pragma once
#include <string>
#include <iostream>

using namespace std;

enum FurnitureType
{
	Oficiu,
	Bucatarie,
	Other
};

class Mobila
{
	protected://proprietatile clasei
		double Pret;
		string Stil;
		FurnitureType Type;
	public:
		//constructorul cu parametri
		Mobila(double pret, string stil, FurnitureType type)
		{
			Pret = pret;
			Stil = stil;
			Type = type;
		}
		//getters
		double GetPret() { return Pret; }
		string GetStil() { return Stil; }
		FurnitureType GetType() { return Type; }
		//setters
		void SetPret(double pret) { Pret = pret; }
		void SetStil(string stil) { this->Stil = stil; }
		void SetType(FurnitureType type) { this->Type = type; }
		//metoda de afisare a informatiilor despre mobila
		virtual string ToString()
		{
			string result = "Pret: " + to_string(Pret) + "\n";
			result += "Stil: " + Stil + "\n";
			result += "Tip: ";
			switch (Type)
			{
				case Oficiu:
					result += "Mobila de oficiu\n";
					break;
				case Bucatarie:
					result += "Mobila pentru bucatarie\n";
					break;
				case Other:
					result += "Alt tip de mobila\n";
					break;
				default:
					break;
			}
			return result;
		}
		//metoda de citire a informatiilor despre mobila
		virtual void Read()
		{
			cout << "Pret: ";
			cin >> Pret;
			cout << "Stilul piesei de mobila: ";
			cin >> Stil;
			cout << "Tip (1-Oficiu/2-Bucatarie/3-altul): ";
			int tip;
			cin >> tip;
			switch (tip)
			{
				case 1:
					Type = Oficiu;
					break;
				case 2:
					Type = Bucatarie;
					break;
				default:
				case 3:
					Type = Other;
					break;
			}
		}
};