using BenchmarkDotNet.Running;
using Lab_3_utils;

namespace Laboratorul_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //run this in Release mode
            BenchmarkRunner.Run<Benchmark2>();
        }
    }
}