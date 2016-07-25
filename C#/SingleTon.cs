using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationExample {
    class Person {

        public static Person Singleton = new Person();
        private Person() {

        }
        public void write() {
            Console.WriteLine("#1");
        }


    }
    class Program {
        static void Main( string[] args ) {
            //ERROR because constructor private
            //Person persion = new Person();
            Person.Singleton.write();

     
        }
    }
}
