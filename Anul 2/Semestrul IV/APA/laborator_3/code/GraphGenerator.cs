namespace Lab_3_utils
{
    public class GraphGenerator
    {
        //mode:
        //fav - 1 - graph with n-1 edges
        //med - 2 - graph with n(n-1)/4
        //defav - 3 - graph with n(n-1)/2
        public static Graf Fav(int nodes)
        {
            //generates a graph with n nodes and n-1 edges of random cost
            Graf graph = new Graf();
            Random rnd = new Random();
            for (int i = 0; i < nodes; i++)
            {
                graph.Noduri.Add(i);
            }
            for (int i = 0; i < nodes - 1; i++)
            {
                graph.Muchii.Add(new Muchie(i, i + 1, rnd.Next(1, 100)));
            }
            return graph;
        }
        public static Graf Med(int nodes)
        {
            //generates a graph with n nodes and n(n-1)/4 edges of random cost
            Graf graph = new Graf();
            Random rnd = new Random();
            for (int i = 0; i < nodes; i++)
            {
                graph.Noduri.Add(i);
            }
            for (int i = 0; i < nodes; i++)
            {
                for (int j = i + 1; j < nodes; j++)
                {
                    if (rnd.Next(0, 2) == 1)// 50% chance of adding an edge
                        graph.Muchii.Add(new Muchie(i, j, rnd.Next(1, 100)));
                }
            }
            return graph;
        }
        public static Graf Defav(int nodes)
        {
            //generates a graph with n nodes and n(n-1)/2 edges of random cost
            Graf graph = new Graf();
            Random rnd = new Random();
            for (int i = 0; i < nodes; i++)
            {
                graph.Noduri.Add(i);
            }
            for (int i = 0; i < nodes; i++)
            {
                for (int j = i + 1; j < nodes; j++)
                {
                    graph.Muchii.Add(new Muchie(i, j, rnd.Next(1, 100)));
                }
            }
            return graph;
        }
    }
}
