using BenchmarkDotNet.Attributes;

namespace Laboratorul_2
{
    [MemoryDiagnoser]
    public class Bench//50,100,1000
    {
        public Bench()
        {
            SortingAlgs = new SortingAlgs();
            generateArray(100, 2);
            printInitialArray();
        }

        private void printInitialArray()
        {
            Console.WriteLine("Array-ul initial");
            for (int i = 0; i < initialArray.Length; i++)
            {
                Console.Write($"{initialArray[i]} ");
            }
            Console.WriteLine();
        }
        private int[] initialArray;
        private int[] ArrayToSort;
        private SortingAlgs SortingAlgs { get; set; }

        void generateArray(int count, int type)//1- crescator//2- descrescator//3- random
        {
            initialArray = new int[count];

            switch (type)
            {
                case 1:
                    {
                        for (int i = 0; i < count; i++)
                        {
                            initialArray[i] = i;
                        }
                        initArrayToSort();
                    }
                    break;
                case 2:
                    {
                        for (int i = 0; i < count; i++)
                        {
                            initialArray[i] = count - i;
                        }
                        initArrayToSort();
                    }
                    break;
                case 3:
                    {
                        Random rd = new Random();
                        for (int i = 0; i < count; i++)
                        {
                            initialArray[i] = rd.Next(0,count);
                        }
                        initArrayToSort();
                    }
                    break;
                default: Console.WriteLine("Invalid generate option"); break;
            }
        }
        void initArrayToSort()
        {
            ArrayToSort = new int[initialArray.Length];

            for (int i = 0; i < initialArray.Length; i++)
            {
                ArrayToSort[i] = initialArray[i];
            }
        }
        
        [Benchmark]
        public void BubleSortWithFlagBenchmark()
        {
            SortingAlgs.bubbleSortWithFlag(ArrayToSort);
            initArrayToSort();
        }
        [Benchmark]
        public void MergeSortBenchmark()
        {
            SortingAlgs.MergeSort(ArrayToSort,0,ArrayToSort.Length-1);
            initArrayToSort();
        }
        [Benchmark]
        public void QuickSortBenchmark()
        {
            SortingAlgs.QuickSort(ArrayToSort, 0, ArrayToSort.Length - 1);
            initArrayToSort();
        }
    }
}
