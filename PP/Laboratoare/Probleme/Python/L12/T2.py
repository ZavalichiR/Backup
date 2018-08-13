from logic import *

a = input("A = ")
b = input("B = ")
c = input("C = ")

xor1 = Xor("Xor1")
xor2 = Xor("Xor2")


and1 = And("And1")
and2 = And("And2")

or1 = Or("Or")

xor1.C.connect(xor2.A)

xor1.C.connect(and2.A)

and2.C.connect(or1.A)
and1.C.connect(or1.B)

xor2.C.monitor = 1
or1.C.monitor = 1

xor1.A.set(a)
xor1.B.set(b)

and1.A.set(a)
and1.B.set(b)

xor2.B.set(c)
and2.B.set(c)
