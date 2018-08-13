from logic import *

a = input("A = ")
b = input("B = ")
c = input("C = ")

and1 = And("A1")
and2 = And("A2")
and3 = And("A3")

not1 = Not("N1")
not2 = Not("N2")

or1 = Or("O1")

xor1 = Xor("X1")

and1.C.connect(and3.A)

or1.C.connect(not1.A)

not1.B.connect(not2.A)
not1.B.connect(and2.A)

and2.C.connect(xor1.B)

not2.B.connect(and3.B)

and3.C.connect(xor1.A)

xor1.C.monitor = 1

and1.A.set(a)
and1.B.set(b)

or1.A.set(a)
or1.B.set(c)

and2.B.set(b)
