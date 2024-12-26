namespace NewtonsMethod
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda lui Newton");

            // Function A: e^x+3x
            Console.WriteLine("A: e^x+3x = 0");
            Newton newtonA = new Newton(1e-8, 100, -0.5);
            double rootA = newtonA.Solve(Data.fx, Data.dfx);
            Console.WriteLine($"Radacina pentru A: {rootA:f4}\n");

            // Function B: x^3 - 30x - 41
            Console.WriteLine("B: x^3 - 23x - 42 = 0");
            Newton newtonB = new Newton(1e-8, 100, -5);
            double rootB = newtonB.Solve(Data.gx, Data.dgx);
            Console.WriteLine($"Radacina pentru B: {rootB:f4}");
        }
    }
}