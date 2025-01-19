using BenchmarkDotNet.Running;

namespace Laboratorul_2
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            BenchmarkRunner.Run<Bench>();
        }
    }
}
