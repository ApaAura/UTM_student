namespace Lab_3_utils
{
    public class Graf
    {
        public List<int> Noduri { get; set; }
        public List<Muchie> Muchii { get; set; }
        public Graf()
        {
            Noduri = new List<int>();
            Muchii = new List<Muchie>();
        }
        public void LoadGraph(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (arr[i, j] != 0)
                    {
                        if (!Noduri.Contains(i))
                            Noduri.Add(i);
                        if (!Noduri.Contains(j))
                            Noduri.Add(j);
                        Muchii.Add(new Muchie(i, j, arr[i, j]));
                    }
                }
            }
        }
        public int[,] ToMatrix()
        {
            int[,] arr = new int[Noduri.Count, Noduri.Count];
            foreach (var muchie in Muchii)
            {
                arr[muchie.Start, muchie.End] = muchie.Cost;
            }
            return arr;
        }
        public static int[,] ReadFromFile(string path)
        {
            StreamReader rd = new StreamReader(path);
            string line = rd.ReadLine();
            int n = int.Parse(line.Split(' ')[0]);
            int v = int.Parse(line.Split(' ')[1]);
            int[,] arr = new int[n+1,n+1];
            for (int i = 0; i < v; i++)
            {
                line = rd.ReadLine();
                int start = int.Parse(line.Split(' ')[0]);
                int end = int.Parse(line.Split(' ')[1]);
                int cost = int.Parse(line.Split(' ')[2]);
                arr[start, end] = cost;
            }
            return arr;
        }
    }
}
