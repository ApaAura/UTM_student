#pragma once
#include <iostream>

using namespace std;

class Progression
{
	protected:
		double FirstTerm;
		double SecondTerm;
	public:
		Progression(double ft, double st)
		{
			FirstTerm = ft;
			SecondTerm = st;
		}
		double GetFirstTerm()
		{
			return FirstTerm;
		}
		void SetFirstTerm(double ft)
		{
			FirstTerm = ft;
		}
		double GetSecondTerm()
		{
			return SecondTerm;
		}
		void SetSecondTerm(double st)
		{
			SecondTerm = st;
		}
		virtual double GetNthTerm(int n)
		{
			return 0;
		}
		virtual double Sum(int n)
		{
			return 0;
		}
};