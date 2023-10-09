using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    class Program
    {
        public interface ICar
        {
            //void Manufacture();
        }

        public interface IBike
        {

        }

        public class TataCar:ICar
        {
            public void Manufacture()
            {

            }
        }
        public class TeslaCar : ICar
        {
            public void Manufacture()
            {

            }
        }
        public class TataBike: IBike
        {
            public void Manufacture()
            {

            }
        }
        public class TeslaBike : IBike
        {
            public void Manufacture()
            {

            }
        }
        //Below is the abstract factory class
        public abstract class VehicleCompany
        {
            public abstract ICar GetCar();
            public abstract IBike GetBike();
        }

        public class TeslaCompany: VehicleCompany
        {
            public override ICar GetCar()
            {
                return new TeslaCar();
            }

            public override IBike GetBike()
            {
                return new TeslaBike();
            }
        }

        //Below 
        public class TataCompany : VehicleCompany
        {
            public override ICar GetCar()
            {
                return new TataCar();
            }

            public override IBike GetBike()
            {
                return new TataBike();
            }
        }

        static void Main(string[] args)
        {
            VehicleCompany vehicleCompany = new TeslaCompany();
            IBike teslaBike = vehicleCompany.GetBike();
            
        }
    }
}
