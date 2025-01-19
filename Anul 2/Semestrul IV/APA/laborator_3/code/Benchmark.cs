using BenchmarkDotNet.Attributes;

namespace Lab_3_utils
{
    [MemoryDiagnoser]
    public class Benchmark
    {
        Graf Graph { get; set; }

        [GlobalSetup]
        public void Setup()
        {
            //Graph = GraphGenerator.Defav(500);
            //Graph = GraphGenerator.Fav(500);
            Graph = GraphGenerator.Med(500);
        }

        [Benchmark]
        public void Prims()
        {
            Algs.Prim(Graph);
        }
        [Benchmark]
        public void Kruskal()
        {
            Algs.Kruskal(Graph);
        }
    }
}
