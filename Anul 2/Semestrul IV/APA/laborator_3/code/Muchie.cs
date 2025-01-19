namespace Lab_3_utils
{
    public class Muchie:IComparable<Muchie>
    {
        public int Start { get; set; }
        public int End { get; set; }
        public int Cost { get; set; }
        public Muchie(int start, int end, int cost)
        {
            Start = start;
            End = end;
            Cost = cost;
        }
        public override string ToString()
        {
            return $"({Start},{End})\t{Cost}";
        }
        public int CompareTo(Muchie? other)
        {
            if (other == null)
                return 1;
            else
                return this.Cost.CompareTo(other.Cost);
        }
    }
}
