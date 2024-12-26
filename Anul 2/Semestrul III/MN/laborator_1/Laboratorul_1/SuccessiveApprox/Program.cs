using NewtonsMethod;

namespace SuccessiveApprox
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda aproximarilor succesive");
            SuccessiveApprox successiveApprox = new SuccessiveApprox(0.0000001, 100, -0.5);
            Console.WriteLine("A: e^x+3x = 0");
            double x = successiveApprox.Solve(Data.fx, SuccesiveApproxData.FiFx);
            Console.WriteLine("B: x^3 - 23x - 42 = 0");
            successiveApprox = new SuccessiveApprox(0.0000001, 100, -5);
            double y = successiveApprox.Solve(Data.gx, SuccesiveApproxData.FiGx);
        }
    }
}