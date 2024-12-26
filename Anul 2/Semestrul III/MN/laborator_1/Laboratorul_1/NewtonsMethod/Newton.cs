namespace NewtonsMethod
{
    public class Newton : Template
    {
        public Newton(double eps, int maxIter, double x0)
        {
            Eps = eps;
            MaxIter = maxIter;
            X0 = x0;
        }

        public double Solve(Func<double, double> f, Func<double, double> df)
        {
            double x = X0; 
            double x1;
            int i = 0;

            Console.WriteLine($"Iteratia: {i}  x = {x:f4}  f(x) = {f(x):f4}  df(x) = {df(x):f4}");

            do
            {
                double dfx = df(x);
                if (Math.Abs(dfx) < 1e-10) 
                {
                    Console.WriteLine("Eroare: Derivata este aproape de zero. Metoda Newton a esuat.");
                    return double.NaN;
                }

                x1 = x - f(x) / dfx;
                Console.WriteLine($"Iteratia: {++i}  x = {x1:f4}  f(x) = {f(x1):f4}  df(x) = {df(x1):f4}");

                if (Math.Abs(f(x1)) < Eps || Math.Abs(x1 - x) < Eps) 
                    break;

                x = x1; 

            } while (i < MaxIter);

            if (i == MaxIter)
                Console.WriteLine("Atentie: Numarul maxim de iteratii a fost atins.");

            return x1;
        }
    }
}
