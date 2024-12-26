using NewtonsMethod;

namespace SecantMethod
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda Secantei");

            // Function A: e^x+3x
            Console.WriteLine("A: e^x+3x = 0");
            Secant secantA = new Secant(1e-8, 100, -0.5, 0.0);
            double rootA = secantA.Solve(Data.fx);
            Console.WriteLine($"Radacina pentru A: {rootA:f5}\n");

            // Function B: x^3 - 23x-42
            Console.WriteLine("B: x^3 - 23x-42 = 0");
            Secant secantB = new Secant(1e-8, 100, -5.0, -4.0);
            double rootB = secantB.Solve(Data.gx);
            Console.WriteLine($"Radacina pentru B: {rootB:f5}");
        }
    }
}