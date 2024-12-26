using NewtonsMethod;

namespace BisectionMethod
{
    namespace BisectionMethod
    {
        internal class Bisection
        {
            private double _a;    
            private double _b;   
            private double _eps;  
            private int _maxIter; 

            public Bisection(double eps, int maxIter, double a, double b)
            {
                _eps = eps;
                _maxIter = maxIter;
                _a = a;
                _b = b;
            }

            public double Solve(Func<double, double> f)
            {
                double x = (_a + _b) / 2;
                int i = 0;

                if (f(_a) * f(_b) > 0)
                {
                    Console.WriteLine("Invalid interval: f(a) and f(b) must have opposite signs.");
                    return double.NaN;
                }

                while (Math.Abs(_b - _a) > _eps && i < _maxIter)
                {
                    x = (_a + _b) / 2;

                    if (f(x) == 0 || Math.Abs(f(x)) < _eps)
                    {
                        break;
                    }

                    if (f(_a) * f(x) < 0)
                    {
                        _b = x;
                    }
                    else
                    {
                        _a = x;
                    }

                    i++;
                    Console.WriteLine($"Iteratia: {i}  x = {x} f(x) = {f(x)}");
                }

                return x;
            }
        }
    }
}