using Lab_3_utils;

namespace Laboratorul_4
{
    internal class Algs2
    {
        //dijkstra algorthm
        public static void Dijkstra(Graf graph, int start)
        {
            int[] dist = new int[graph.Noduri.Count];
            int[] prev = new int[graph.Noduri.Count];
            bool[] visited = new bool[graph.Noduri.Count];
            for (int i = 0; i < graph.Noduri.Count; i++)
            {
                dist[i] = int.MaxValue;
                prev[i] = -1;
                visited[i] = false;
            }
            dist[start] = 0;
            for (int i = 0; i < graph.Noduri.Count; i++)
            {
                int u = MinDistance(dist, visited);
                visited[u] = true;
                foreach (var muchie in graph.Muchii)
                    if (muchie.Start == u)
                        if (!visited[muchie.End] && dist[u] != int.MaxValue && dist[u] + muchie.Cost < dist[muchie.End])
                        {
                            dist[muchie.End] = dist[u] + muchie.Cost;
                            prev[muchie.End] = u;
                        }
            }
            PrintSolution(dist, prev, start);
        }
        //Floyd algorithm
        public static void Floyd(Graf graph)
        {
            int[,] dist = new int[graph.Noduri.Count, graph.Noduri.Count];
            int[,] prev = new int[graph.Noduri.Count, graph.Noduri.Count];
            for (int i = 0; i < graph.Noduri.Count; i++)
                for (int j = 0; j < graph.Noduri.Count; j++)
                {
                    dist[i, j] = int.MaxValue;
                    prev[i, j] = -1;
                }
            for (int i = 0; i < graph.Noduri.Count; i++)
                dist[i, i] = 0;
            foreach (var muchie in graph.Muchii)
            {
                dist[muchie.Start, muchie.End] = muchie.Cost;
                prev[muchie.Start, muchie.End] = muchie.Start;
            }
            for (int k = 0; k < graph.Noduri.Count; k++)
                for (int i = 0; i < graph.Noduri.Count; i++)
                    for (int j = 0; j < graph.Noduri.Count; j++)
                        if (dist[i, k] != int.MaxValue && dist[k, j] != int.MaxValue && dist[i, k] + dist[k, j] < dist[i, j])
                        {
                            dist[i, j] = dist[i, k] + dist[k, j];
                            prev[i, j] = prev[k, j];
                        }
            PrintSolution(dist);
        }

        private static void PrintSolution(int[,] dist)
        {
            for (int i = 0; i < dist.GetLength(0); ++i)
            {
                for (int j = 0; j < dist.GetLength(1); ++j)
                {
                    if (dist[i, j] == int.MaxValue)
                    {
                        Console.Write("I ");
                    }
                    else
                    {
                        Console.Write(dist[i, j] + " ");
                    }
                }
                Console.WriteLine();
            }
        }
        private static int MinDistance(int[] dist, bool[] visited)
        {
            int min = int.MaxValue;
            int min_index = -1;
            for (int i = 0; i < dist.Length; i++)
            {
                if (!visited[i] && dist[i] <= min)
                {
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }
       
        private static void PrintSolution(int[] dist, int[] prev, int start)
        {
            Console.WriteLine("Vertex\tDistance\tPath");
            for (int i = 0; i < dist.Length; i++)
            {
                if (i != start)
                {
                    Console.Write(start + " -> " + i + "\t\t" + dist[i] + "\t\t" + start);
                    PrintPath(prev, i);
                    Console.WriteLine();
                }
            }
        }
        
        private static void PrintPath(int[] prev, int i)
        {
            if (prev[i] == -1)
                return;
            PrintPath(prev, prev[i]);
            Console.Write(" -> " + i);
        }
    }
}
