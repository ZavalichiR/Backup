import threading
import queue
queue.Queue()

from threading import Thread


class sumaN(threading.Thread):
    def __init__(self,n):
        threading.Thread.__init__(self)
        self.n=n
        self.s=0
    def run(self):        
        for i in range(0,self.n+1):
                self.s=self.s+i
                #print(self.s)
        return self.s
    def process_data(tName, q):
        while not doExit:
            queueLock.acquire()
            if not workQueue.empty():
                data = q.get()
                queueLock.release()
            else:
                queueLock.release()
            time.sleep(1)


myTask=[16,4,10,24]

queueLock = threading.Lock()
workQueue = queue.Queue(10)
threads = []
tID = 1
for i in myTask:
    thread = sumaN(i)
    thread.start()
    print("Sum[",i,"]=",thread.s)
    threads.append(thread)
    tID += 1
queueLock.acquire()
for i in myTask:
    workQueue.put(i)
queueLock.release()
while not workQueue.empty():
    pass
doExit = 1
for t in threads:
    t.join()
print ("Exiting Main Thread")

