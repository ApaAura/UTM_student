using BisectionMethod.BisectionMethod;
using NewtonsMethod;

namespace BisectionMethod
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda Bisectiei (Injumatatirii Intervalului)");

            // Function A: e^x + 3x
            Func<double, double> fx = x => Math.Exp(x) + 3 * x;
            Console.WriteLine("A: Solving e^x + 3x = 0");
            Bisection bisectionA = new Bisection(1e-7, 100, -1, 0); 
            double rootA = bisectionA.Solve(Data.fx);
            Console.WriteLine($"Radacina pentru A: {rootA:f5}\n");

            // Function B: x^3 - 23x - 42
            Func<double, double> gx = x => Math.Pow(x, 3) - 23 * x - 42;
            Console.WriteLine("B: Solving x^3 - 23x - 42 = 0");
            Bisection bisectionB = new Bisection(1e-7, 100, -5, 5); 
            double rootB = bisectionB.Solve(Data.gx);
            Console.WriteLine($"Radacina pentru B: {rootB:f5}");
        }
    }
}
