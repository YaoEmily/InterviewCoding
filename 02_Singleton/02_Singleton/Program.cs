using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02_Singleton
{
    public sealed class Singlenton1
    {
        private Singlenton1()
        {

        }

        public static Singlenton1 instance = null;
        public static Singlenton1 Instance
        {
            get{
                if(instance == null)
                {
                    instance = new Singlenton1();
                }

                return instance;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Singlenton1 sing1 = Singlenton1.Instance;
            Singlenton1 sing2 = Singlenton1.Instance;
            if (sing1 == sing2)
            {
                Console.WriteLine("equal");
            }
            else
            {
                Console.WriteLine("unequal");
            }
        }
    }
}
