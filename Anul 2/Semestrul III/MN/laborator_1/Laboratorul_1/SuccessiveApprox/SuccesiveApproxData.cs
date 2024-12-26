using NewtonsMethod;

namespace SuccessiveApprox
{
    public class SuccesiveApproxData:Data
    {
        public static double FiFx(double x)
        {
            double res = Math.Pow(Math.E, x) + 3 * x;
            return res;
        }
        public static double FiGx(double x)
        {
            double res = x - gx(x)/45;
            return res;
        }
    }
}
