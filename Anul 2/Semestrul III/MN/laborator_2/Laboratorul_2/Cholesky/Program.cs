using InputData;

namespace Cholesky
{
    internal class Program
    {
        static public double[,] L;
        static public double[,] Lt;
        static void Main(string[] args)
        {
            Console.WriteLine("Metoda lui Cholecky pentru Ax = B");
            //InpData.PrintInputData();
            InpData.PrintA();
            CholeskyDecomposition(InpData.GetA(), InpData.n);
            Console.WriteLine("Verificarea rezultatelor:\nProdusul matricelor L*Lt:");
            MatrixProduct(L, Lt);
        }
        static void CholeskyDecomposition(double[,] matrix, int n)
        {
            double[,] lower = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    double sum = 0;
                    if (j == i)
                    {
                        for (int k = 0; k < j; k++)
                            sum += Math.Pow(lower[j, k] , 2);
                        lower[j, j] = Math.Sqrt(matrix[j, j] - sum);
                    }
                    else
                    {
                        for (int k = 0; k < j; k++)
                            sum += (lower[i, k] * lower[j, k]);
                        lower[i, j] = (matrix[i, j] - sum) / lower[j, j];
                    }
                }
            }
            L = new double[n, n];
            Lt = new double[n, n];
            Console.WriteLine("Matricea L:");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0,8:0.0000}", lower[i, j]);
                    L[i, j] = lower[i, j];
                }
                Console.WriteLine();
            }
            Console.WriteLine("Matricea L transpusa:");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0,8:0.0000}", lower[j, i]);
                    Lt[i, j] = lower[j, i];
                }
                Console.WriteLine();
            }
        }
        static void MatrixProduct(double[,]A, double[,]B)
        {
           double[,] C = new double[A.GetLength(0), B.GetLength(1)];
                for (int i = 0; i < A.GetLength(0); i++)
                {
                    for (int j = 0; j < B.GetLength(1); j++)
                    {
                        for (int k = 0; k < A.GetLength(1); k++)
                        {
                            C[i, j] += A[i, k] * B[k, j];
                        }
                    }
                }
                for (int i = 0; i < A.GetLength(0); i++)
                {
                    for (int j = 0; j < B.GetLength(1); j++)
                    {
                        Console.Write("{0,8:0.0000}", C[i, j]);
                    }
                    Console.WriteLine();
                }
        }
    }
}