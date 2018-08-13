from logic import *

a=input("A= ")
b=input("B= ")
c=input("C= ")

and1=And("And1")
and2=And("And2")
and3=And("And3")

or1=Or("Or")

xor1=Xor("Xor")

not1=Not("Not1")
not2=Not("Not2")

and1.C.connect(and2.A)

or1.C.connect(not1.A)
not1.B.connect(not2.A)
not1.B.connect(and3.A)

not2.B.connect(and2.B)

and2.C.connect(xor1.A)
and3.C.connect(xor1.B)

and2.C.monitor=1
and3.C.monitor=1
xor1.C.monitor=1

and1.A.set(a)
and1.B.set(b)
or1.A.set(c)
or1.B.set(a)
and3.B.set(b)
