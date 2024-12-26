using NewtonsMethod;
namespace SecantMethod
{
    public class Secant : Template
    {
        public double X1 { get; set; }
        public Secant(double eps, int maxIter, double x0, double x1)
        {
            Eps = eps;
            MaxIter = maxIter;
            X0 = x0;
            X1 = x1;
        }
        public double Solve(Func<double, double> f)
        {
            double f0 = f(X0);
            double f1 = f(X1);

            for (int i = 0; i < MaxIter; i++)
            {
                double x2 = X1 - f1 * (X1 - X0) / (f1 - f0);
                double f2 = Math.Pow(Math.E, x2) + 3 * x2;

                if (Math.Abs(x2 - X1) < Eps)
                {
                    return x2;
                }
                Console.WriteLine($"Iteratia: {i + 1}  x = {x2:f5} f(x) = {f(x2):f5}");

                X0 = X1;
                f0 = f1;
                X1 = x2;
                f1 = f2;
            }

            Console.WriteLine("Metoda secantei nu converge.");
            return double.NaN;
        }
    }
}
