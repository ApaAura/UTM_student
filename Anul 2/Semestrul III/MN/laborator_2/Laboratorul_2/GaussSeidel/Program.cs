using InputData;

namespace GaussSeidel
{
    internal class Program
    {
        public static double Epsilon { get; set; } = 0.00001;
        public static int MaxIterations { get; set; } = 100;
        public static double[] value0 { get; set; } = new double[InpData.n];
        public static double[] value1 { get; set; } = new double[InpData.n];
        public static double[] epsilons { get; set; } = new double[InpData.n];

        static void Main(string[] args)
        {
            Console.WriteLine("Metoda lui Gauss-Seidel pentru Ax = B");
            int iter = 0;
            Console.WriteLine("\t\tX1\t\tX2\t\tX3\t\tX4");
            do
            {
                value1[0] = InpData.X1(value0[1], value0[2], value0[3]);
                value1[1] = InpData.X2(value0[0], value0[2], value0[3]);
                value1[2] = InpData.X3(value0[0], value0[1], value0[3]);
                value1[3] = InpData.X4(value0[0], value0[1], value0[2]);
                Console.Write($"Iteratia {iter}: ");
                PrintActualSolution();
                doEpsilons();
                iter++;
                Transfer();
            } while (CheckEpsilons() && iter <= MaxIterations);
        }

        static void PrintActualSolution()
        {
            for (int i = 0; i < value1.Length; i++)
            {
                Console.Write($"X{i + 1} = {value1[i]:f6}; ");
            }
            Console.WriteLine();
        }

        static void doEpsilons()
        {
            for (int i = 0; i < value0.Length; i++)
            {
                epsilons[i] = Math.Abs(value0[i] - value1[i]);
            }
        }

        static void Transfer()
        {
            for (int i = 0; i < value0.Length; i++)
            {
                value0[i] = value1[i];
            }
        }

        static bool CheckEpsilons()
        {
            for (int i = 0; i < epsilons.Length; i++)
                if (epsilons[i] < Epsilon)
                    return false;
            return true;
        }
    }
}