using NewtonsMethod;

namespace SuccessiveApprox
{
    public class SuccessiveApprox:Template
    {
        public SuccessiveApprox(double eps, int maxIter, double x0)
        {
            Eps = eps;
            MaxIter = maxIter;
            X0 = x0;
        }
        public double Solve(Func<double, double> f, Func<double, double> g)
        {
            double x = X0;
            double x1 = g(x);
            int i = 0;
            while (Math.Abs(x1 - x) > Eps && i < MaxIter)
            {
                x = x1;
                x1 = g(x);
                i++;
                Console.WriteLine($"Iteratia: {i}  x = {x1:f5} f(x) = {f(x1):f5}");
            }
            return x1;
        }
    }
}
