namespace NewtonsMethod
{
    public class Data
    {
        // Function A: e^x+3x
        public static double fx(double x) => Math.Pow(Math.E, x) + 3 * x;

        public static double dfx(double x) => Math.Pow(Math.E, x) + 3;

        // Function B: x^3 - 23x-42
        public static double gx(double x) => Math.Pow(x, 3) - 23 * x - 42;

        public static double dgx(double x) => 3 * Math.Pow(x, 2) - 23;
    }
}
