# TCP Client Code
#netstat -an (in cmd)
host="127.0.0.1"                # Seteaza variabila host
port=5939                       # Seteaza variabila port 4446
from socket import *             # Importa socket module

s=socket(AF_INET, SOCK_STREAM)   # Creaza socket-ul

s.connect((host,port))           # Se conecteaza la server

while 1:
    msg=s.recv(1024)    

    print ("Mesajul primit : " + msg)
    data=input("Introduceti mesajul : ")
    if not data: break

    s.send(data)

s.close()                            # Inchide socket-ul





# TCP Server Code

host="127.0.0.1"                 # Seteaza variabila host
port=5939                        # Seteaza variabila port 4446
from socket import *             # Importa socket module

s=socket(AF_INET, SOCK_STREAM)

s.bind((host,port))
s.listen(1)                     

print ("Se asteapta conexiunea.. ")

q,addr=s.accept()              

while 1:
    data=input("Introduceti mesajul :  ")  
    q.send(data)                       

    msg=q.recv(1024)
    if not msg: break

    print ("Mesajul primit : " + msg)

s.close()
