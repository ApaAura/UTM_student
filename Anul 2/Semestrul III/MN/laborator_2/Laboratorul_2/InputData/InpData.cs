namespace InputData
{
    public class InpData
    {
        static public int n = 4;
        static public double[,] AB = { {0, 0, 0, 0, 0, 0},
                                       {0, 8.1,  -0.9,  0.6, 0.8, 7.2 },
                                       {0, -0.9,  14.3,  0.3,  0.7, 10.3 },
                                       {0, 0.6,  0.3,  7.9, -0.4, -11.9 },
                                       {0, 0.8,  0.7, -0.4,  10.6, 9.2 }};
        static public double[,] GetA()
        {
            double[,] A = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    A[i, j] = AB[i+1, j+1];
                }
            }
            return A;
        }
        static public double[] GetB()
        {
            double[] B = new double[n];
            for (int i = 1; i <= n; i++)
            {
                B[i-1] = AB[i , n + 1];
            }
            return B;
        }
        static public void PrintA()
        {
            Console.WriteLine("Matricea A:");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0,8:0.0000}", AB[i + 1, j + 1]);
                }
                Console.WriteLine();
            }
        }

        static public void PrintInputData()
        {
            PrintA();
            Console.WriteLine("Vectorul B:");
            for (int i = 1; i <= n; i++)
            {
                Console.WriteLine("{0,8:0.0000}", AB[i, n + 1]);
            }
        }
        //Gauss-Seidel functions
        static public double X1(double x2, double x3, double x4)
        {
            //Console.WriteLine($"{AB[1, n + 1]} - {AB[1, 2]} * {x2} - {AB[1, 3]} * {x3} - {AB[1, 4]} * {x4}) / {AB[1, 1]}");
            return (AB[1, n + 1] - AB[1, 2] * x2 - AB[1, 3] * x3 - AB[1, 4] * x4) / AB[1, 1];
        }
        static public double X2(double x1, double x3, double x4)
        {
            //Console.WriteLine($"{AB[2, n + 1]} - {AB[2, 1]} * {x1} - {AB[2, 3]} * {x3} - {AB[2, 4]} * {x4}) / {AB[2, 2]}");
            return (AB[2, n + 1] - AB[2, 1] * x1 - AB[2, 3] * x3 - AB[2, 4] * x4) / AB[2, 2];
        }
        static public double X3(double x1, double x2, double x4)
        {
            //Console.WriteLine($"{AB[3, n + 1]} - {AB[3, 1]} * {x1} - {AB[3, 2]} * {x2} - {AB[3, 4]} * {x4}) / {AB[3, 3]}");
            return (AB[3, n + 1] - AB[3, 1] * x1 - AB[3, 2] * x2 - AB[3, 4] * x4) / AB[3, 3];
        }
        static public double X4(double x1, double x2, double x3)
        {
            //Console.WriteLine($"{AB[4, n + 1]} - {AB[4, 1]} * {x1} - {AB[4, 2]} * {x2} - {AB[4, 3]} * {x3}) / {AB[4, 4]}");
            return (AB[4, n + 1] - AB[4, 1] * x1 - AB[4, 2] * x2 - AB[4, 3] * x3) / AB[4, 4];
        }
    }
}
