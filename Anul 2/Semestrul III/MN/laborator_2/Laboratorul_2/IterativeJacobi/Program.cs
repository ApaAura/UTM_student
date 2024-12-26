using InputData;

namespace IterativeJacobi
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda iterativa a lui Jacobi pentru Ax = B");
            InpData.PrintInputData();
            Console.WriteLine("\t\tX1\t\tX2\t\tX3\t\tX4");
            Jacobi(InpData.GetA(), InpData.GetB(), new double[InpData.n], 0.00001);
        }
        static void Jacobi(double[,] A, double[] b, double[] x, double epsilon)
        {
            int size = A.GetLength(0);
            double[] D = new double[size];
            double[,] R = new double[size, size];
            for (int i = 0; i < size; i++)
            {
                D[i] = A[i, i];
                for (int j = 0; j < size; j++)
                {
                    if (i != j)
                    {
                        R[i, j] = A[i, j];
                    }
                }
            }
            bool converged = false;
            int iterations = 0;
            while (!converged)
            {
                double[] xNew = new double[size];
                for (int j = 0; j < size; j++)
                {
                    double sum = 0;
                    for (int k = 0; k < size; k++)
                    {
                        if (k != j)
                        {
                            sum += R[j, k] * x[k];
                        }
                    }
                    xNew[j] = (b[j] - sum) / D[j];
                }
                iterations++;
                converged = true;
                for (int j = 0; j < size; j++)
                {
                    if (Math.Abs(x[j] - xNew[j]) > epsilon)
                    {
                        converged = false;
                        break;
                    }
                }
                x = xNew;
                Console.Write($"Iteratia {iterations}: ");
                PrintActualSolution(x);
            }
        }
        static void PrintActualSolution(double[] x)
        {
            for (int i = 0; i < x.Length; i++)
            {
                Console.Write($"X{i + 1} = {x[i]:f6}; ");
            }
            Console.WriteLine();
        }
    }
}