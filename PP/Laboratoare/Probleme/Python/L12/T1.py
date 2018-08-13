from logic import *

a = input('A= ')
b = input('B= ')
c = input('C= ')


notA = Not("NotA")
notB = Not("NotB")
notC = Not("NotC")

and1 = And("And1")
and2 = And("And2")
and3 = And("And3")
#Ultimul And are 3 intrari --> 2-AND cu 2 intrari
and4 = And("And4")
and5 = And("And5")



notB.B.connect(and1.A)
notC.A.connect(and1.B)

notA.B.connect(and2.A)
notB.B.connect(and2.B)

notA.A.connect(and3.A)
notB.B.connect(and3.B)

notA.B.connect(and4.A)
notB.A.connect(and4.B)

notC.A.connect(and5.A)
and4.C.connect(and5.B)

or1 = Or("Or1")
or2 = Or("Or2")
or3 = Or("Or3")


and1.C.connect(or1.A)
and2.C.connect(or1.B)

and3.C.connect(or2.A)
and5.C.connect(or2.B)

or1.C.connect(or3.A)
or2.C.connect(or3.B)

or3.C.monitor = 1

notA.A.set(a)
notB.A.set(b)
notC.A.set(c)
