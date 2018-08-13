from logic import *
#Creare porti
a=And("A1")
n=Not("N1")

#Conexiuni
a.C.connect(n.A)#conectare iesirea lui a la intrarea lui n

#Monitor
n.B.monitor=1

a.A.set(0)
a.B.set(1)


      
