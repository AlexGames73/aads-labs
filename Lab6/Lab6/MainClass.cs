using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab6
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            HashSet<int> hashSet = new HashSet<int>();
            ArrayList arrayList = new ArrayList();
            List<int> list = new List<int>();
            Queue queue = new Queue();
            Stack stack = new Stack();

            Console.WriteLine("\nTest #1");
            long t = DateTime.Now.Ticks;
            for (int i = 0; i < 10000000; i++)
                hashSet.Add(i);
            Console.WriteLine("Добавление 10000000 элементов в HashSet: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 10000000; i++)
                arrayList.Add(i);
            Console.WriteLine("Добавление 10000000 элементов в ArrayList в конец: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 10000000; i++)
                list.Add(i);
            Console.WriteLine("Добавление 10000000 элементов в List в конец: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 10000000; i++)
                queue.Enqueue(i);
            Console.WriteLine("Добавление 10000000 элементов в Queue в конец: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 10000000; i++)
                stack.Push(i);
            Console.WriteLine("Добавление 10000000 элементов в Stack в конец: {0:N0}", DateTime.Now.Ticks - t);


            Console.WriteLine("\nTest #2");
            t = DateTime.Now.Ticks;
            for (int i = 0; i < 600; i++)
                arrayList.Insert(2500000, 9999998 - i);
            Console.WriteLine("Добавление 600 элементов в ArrayList в середину: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 600; i++)
                list.Insert(2500000, 9999998 - i);
            Console.WriteLine("Добавление 600 элементов в List в середину: {0:N0}", DateTime.Now.Ticks - t);


            Console.WriteLine("\nTest #3");
            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                hashSet.Contains(9999999);
            Console.WriteLine("200 contains проверок максимального числа в HashSet: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                arrayList.Contains(9999999);
            Console.WriteLine("200 contains проверок максимального числа в ArrayList: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                list.Contains(9999999);
            Console.WriteLine("200 contains проверок максимального числа в List: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                queue.Contains(9999999);
            Console.WriteLine("200 contains проверок максимального числа в Queue: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                stack.Contains(9999999);
            Console.WriteLine("200 contains проверок максимального числа в Stack: {0:N0}", DateTime.Now.Ticks - t);


            Console.WriteLine("\nTest #4");
            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                hashSet.Contains(0);
            Console.WriteLine("200 contains проверок минимального числа в HashSet: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                arrayList.Contains(0);
            Console.WriteLine("200 contains проверок минимального числа в ArrayList: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                list.Contains(0);
            Console.WriteLine("200 contains проверок минимального числа в List: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                queue.Contains(0);
            Console.WriteLine("200 contains проверок минимального числа в Queue: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                stack.Contains(0);
            Console.WriteLine("200 contains проверок минимального числа в Stack: {0:N0}", DateTime.Now.Ticks - t);


            Console.WriteLine("\nTest #5");
            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                hashSet.Remove(i);
            Console.WriteLine("200 удалений в HashSet: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                arrayList.Remove(i);
            Console.WriteLine("200 удалений в ArrayList: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                list.Remove(i);
            Console.WriteLine("200 удалений в List: {0:N0}", DateTime.Now.Ticks - t);


            Console.WriteLine("\nTest #6");
            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                queue.Dequeue();
            Console.WriteLine("200 доставаний в Queue: {0:N0}", DateTime.Now.Ticks - t);

            t = DateTime.Now.Ticks;
            for (int i = 0; i < 200; i++)
                stack.Pop();
            Console.WriteLine("200 доставаний в Stack: {0:N0}", DateTime.Now.Ticks - t);
        }
    }
}
