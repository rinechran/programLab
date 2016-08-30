using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class Program
    {

        class Adaptee
        {
            // Provide full precision
            public double SpecificRequest(double a, double b)
            {
                return a / b;
            }
        }

        // Required standard for requests
        interface ITarget
        {
            // Rough estimate required
            string Request(int i);
        }

        // Implementing the required standard via Adaptee
        class Adapter : Adaptee, ITarget
        {
            public string Request(int i)
            {
                return "Rough estimate is " + (int)Math.Round(SpecificRequest(i, 3));
            }
        }


        static void Main(string[] args)
        {
            // Showing the Adapteee in standalone mode
            Adaptee first = new Adaptee();
            Console.Write("Before the new standard\nPrecise reading: ");
            Console.WriteLine(first.SpecificRequest(5, 3));

            // What the client really wants
            ITarget second = new Adapter();
            Console.WriteLine("\nMoving to the new standard");
            Console.WriteLine(second.Request(5));

        }
    }
}
