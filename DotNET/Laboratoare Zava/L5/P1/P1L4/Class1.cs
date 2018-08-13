﻿

using System;
using System.Runtime.Remoting.Lifetime;

namespace MathLibrary
{
    public class SimpleMath : MarshalByRefObject
    {
        public SimpleMath()
        { Console.WriteLine("SimpleMath ctor called"); }
        public int Add(int n1, int n2)
        {
            ILease lease = (ILease)this.GetLifetimeService();
            Console.WriteLine(lease.CurrentLeaseTime);
            Console.WriteLine("SimpleMath.Add({0}, {1})", n1, n2);
            return n1 + n2;
        }
        public int Subtract(int n1, int n2)
        {
            Console.WriteLine("SimpleMath.Subtract({0}, {1})", n1, n2);
            return n1 - n2;
        }
        public override Object InitializeLifetimeService()
        {
            ILease lease = (ILease)base.InitializeLifetimeService();
            if (lease.CurrentState == LeaseState.Initial)
            {
                lease.RenewOnCallTime = TimeSpan.FromSeconds(10);
                lease.RenewOnCallTime = TimeSpan.FromSeconds(20);
                lease.RenewOnCallTime = TimeSpan.FromSeconds(2);

            }
            return lease;
        }
    }
}
