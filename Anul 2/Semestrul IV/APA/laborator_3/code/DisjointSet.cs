namespace Lab_3_utils
{
    public class DisjointSet
    {
        public List<int> Nodes { get; set; }
        public DisjointSet(int node)
        {
            Nodes = new List<int>();
            Nodes.Add(node);
        }
        public bool Contains(int node)
        {
            return Nodes.Contains(node);
        }
        public void Merge(DisjointSet set)
        {
            Nodes.AddRange(set.Nodes);
        }
    }
}
