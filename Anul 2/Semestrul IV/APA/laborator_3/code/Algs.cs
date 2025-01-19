namespace Lab_3_utils
{
    public class Algs
    {
        public static void Kruskal(Graf graph)
        {
            //sort edges by cost
            graph.Muchii.Sort((x, y) => x.Cost.CompareTo(y.Cost));
            //create disjoint sets
            List<DisjointSet> sets = new List<DisjointSet>();
            foreach (int node in graph.Noduri)
            {
                sets.Add(new DisjointSet(node));
            }
            //create MST
            List<Muchie> MST = new List<Muchie>();
            foreach (Muchie edge in graph.Muchii)
            {
                //find sets containing the nodes of the edge
                DisjointSet set1 = null;
                DisjointSet set2 = null;
                foreach (DisjointSet set in sets)
                {
                    if (set.Contains(edge.Start))
                        set1 = set;
                    if (set.Contains(edge.End))
                        set2 = set;
                }
                //if the sets are different, merge them and add the edge to the MST
                if (set1 != set2)
                {
                    set1.Merge(set2);
                    sets.Remove(set2);
                    MST.Add(edge);
                }
            }
            //print MST
            PrintMST(MST);
        }
        public static void Prim(Graf graph)
        {
            //create a list of edges in the MST
            List<Muchie> MST = new List<Muchie>();
            //create a list of visited nodes
            List<int> visited = new List<int>();
            //add the first node to the visited list
            visited.Add(graph.Noduri[0]);
            //while there are still nodes to visit
            while (visited.Count < graph.Noduri.Count)
            {
                //create a list of edges that connect to visited nodes
                List<Muchie> edges = new List<Muchie>();
                foreach (var edge in graph.Muchii)
                {
                    if (visited.Contains(edge.Start) && !visited.Contains(edge.End))
                    {
                        edges.Add(edge);
                    }
                }
                //sort the edges by cost
                edges.Sort((x, y) => x.Cost.CompareTo(y.Cost));
                //add the cheapest edge to the MST
                MST.Add(edges[0]);
                //add the new node to the visited list
                visited.Add(edges[0].End);
            }
            PrintMST(MST);
        }
        private static void PrintMST(List<Muchie> MST)
        {
            Console.WriteLine("MST:");
            foreach (var edge in MST)
            {
                Console.WriteLine(edge);
            }
        }
    }
}
