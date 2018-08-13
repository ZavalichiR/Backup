import threading
from threading import Thread


class sumaN(threading.Thread):
    def __init__(self,x,y):
        threading.Thread.__init__(self)
        self.x=x
        self.y=y
        self.s=0
    def run(self):
        
        for i in range(int(self.x),int(self.y)+1):
                self.s=self.s+i
        return self.s



n=16
n1=sumaN(1,n/4)
n2=sumaN(n/4+1,n/2)
n3=sumaN(n/2+1,3*n/4)
n4=sumaN(3*n/4+1,n)
n1.start()
n2.start()
n3.start()
n4.start()

print("Suma este cifrelor numarului ",n," este :",n1.s+n2.s+n3.s+n4.s)
