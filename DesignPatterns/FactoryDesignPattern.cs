using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    public interface ICar
    {
        void Start();
    }

    public class SixSeaterCar: ICar
    {
        public void Start()
        {
            
        }
    }

    public class FourSeaterCar: ICar
    {
        public void Start()
        {

        }
    }

    public class CarFactory
    {
        public ICar GetCar(string carSeaterType)
        {
            switch (carSeaterType)
            {
                case "Four": return new FourSeaterCar();
                default:
                    return new SixSeaterCar();
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //ICar sixSeater = new SixSeaterCar();
            //ICar fourSeater = new FourSeaterCar();

            CarFactory carFactory = new CarFactory();
            ICar fourSeater = carFactory.GetCar("Four");
        }
    }
}
