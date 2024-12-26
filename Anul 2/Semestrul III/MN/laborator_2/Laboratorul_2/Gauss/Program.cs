using InputData;

namespace Gauss
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda eliminarii lui Gauss pentru Ax = B");
            InpData.PrintInputData();
            Solution(Solve(EliminariGauss(InpData.AB, InpData.n), InpData.n));
        }
        static double[,] EliminariGauss(double[,]a, int n)
        {
            double ratio = 0;
            for (int i = 1; i <= n - 1; i++)
            {
                if (a[i,i] == 0.0)
                {
                    Console.WriteLine("Eroare Matematica");
                    break;
                }
                for (int j = i + 1; j <= n; j++)
                {
                    ratio = a[j,i] / a[i,i];

                    for (int k = 1; k <= n + 1; k++)
                    {
                        a[j,k] = a[j,k] - ratio * a[i,k];
                    }
                }
            }
            return a;
        }
        //Obtinerea solutiei prin metoda de inlocuire inversa
        static double[] Solve(double[,] a, int n)
        {
            double [] x = new double[n + 1];
            x[n] = a[n,n + 1] / a[n,n];

            for (int i = n - 1; i >= 1; i--)
            {
                x[i] = a[i,n + 1];
                for (int j = i + 1; j <= n; j++)
                {
                    x[i] = x[i] - a[i,j] * x[j];
                }
                x[i] = x[i] / a[i,i];
            }
            return x;
        }
        //Afisarea solutiei 
        static void Solution(double[] x)
        {
            Console.WriteLine("Solutia este:");
            for (int i = 1; i < x.GetLength(0); i++)
            {
                Console.WriteLine($"x{i} = {x[i]:F4}");
            }
        }
    }
}