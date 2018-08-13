class Automat:
        def __init__(self):
        	self.state=0;
        def stZero(self,coin):
        	if coin==5:
        		self.state=5
        		print("Coins: %d"%(self.state))
        	elif coin==10:
        		self.state=10
        		print("Coins: %d"%(self.state))
        def stFive(self,coin):
                if coin==5:
                        self.state=10
                        print("Coins: %d"%(self.state))
                elif coin==10:
                        self.state=15
                        print("Coins: %d"%(self.state))
        def stTen(self,coin):
                if coin==5:
                	self.state=15
                	print("Coins: %d"%(self.state))
                elif coint==10:
                	self.state=20
                	print("Coins: %d"%(self.state))
        def st15(self,coin):
                if coin==5:
                        self.state=20
                        print("Coins: %d"%(self.state))
                elif coint==10:
                        self.state=20
                        print("Coins: %d"%(self.state))
        def nextState(self,coin):
                if self.state==0: self.stZero(coin)
                elif self.state==5: self.stFive(coin)
                elif self.state==10: self.stTen(coin)
                elif self.state==15: self.st15(coin)
                elif self.state==20:self.stZero(coin)
        def run(self):
                while(1):
                        coin=input("Coins: ")
                        self.nextState(coin)
                        print("Coins: %d"%(self.state))
                        if self.state == 20: print ("Coffee ready!")

def main():
        a=Automat()
        a.run()

main()
