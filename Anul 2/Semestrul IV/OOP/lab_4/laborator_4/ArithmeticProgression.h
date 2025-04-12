#pragma once
#include "Progression.h"
class ArithmeticProgression : public Progression
{
	public:
		ArithmeticProgression(double ft, double st) : Progression(ft, st) 
		{
			
		}
		double GetNthTerm(int n) override
		{
			return GetFirstTerm() + (n * GetSecondTerm());
		}
		double Sum(int n) override
		{
			return (n + 1) * (GetFirstTerm() + GetNthTerm(n)) / 2;
		}
};

