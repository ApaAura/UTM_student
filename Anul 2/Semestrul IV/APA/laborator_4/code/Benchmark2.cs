using BenchmarkDotNet.Attributes;
using Lab_3_utils;

namespace Laboratorul_4
{
    [MemoryDiagnoser]
    public class Benchmark2
    {
        Graf Graph { get; set; }

        [GlobalSetup]
        public void Setup()
        {
            //Graph = GraphGenerator.Defav(1000);
            //Graph = GraphGenerator.Fav(1000);
            Graph = GraphGenerator.Med(900);
            
        }
        [Benchmark]
        public void DijkstraBench()
        {
            Algs2.Dijkstra(Graph,0);
        }
        [Benchmark]
        public void FloydBench()
        {
            Algs2.Floyd(Graph);
        }
    }
}
