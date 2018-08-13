import threading
from threading import Thread


class squareNumber(threading.Thread):
    def __init__(self,n):
        threading.Thread.__init__(self)
        self.n = n
    def run(self):
        rez=self.n**2
        print("\npatrat=",rez," ")


class sumaN(threading.Thread):
    def __init__(self,n):
        threading.Thread.__init__(self)
        self.n = n
    def run(self):
        s=0;
        for i in range(1,self.n+1):
                s=s+i
        print("\nsum=",s," ")


th=squareNumber(4)
th2=sumaN(16)
th.start()
th2.start()
