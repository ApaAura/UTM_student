#pragma once
#include "Progression.h"

class GeometricProgression : public Progression
{
	public:
		GeometricProgression(double ft, double st) : Progression(ft, st)
		{
		}
		double GetNthTerm(int n) override
		{
			return GetFirstTerm() * pow(GetSecondTerm(), n);
		}
		double Sum(int n) override
		{
			return (GetFirstTerm() - GetNthTerm(n)*GetSecondTerm()) / (1 - GetSecondTerm());
		}
};

