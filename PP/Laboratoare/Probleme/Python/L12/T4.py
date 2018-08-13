
stare = {}
stare[0] = "0 cents deposited"
stare[1] = "5 cents deposited"
stare[2] = "10 cents deposited"
stare[3] = "15 cents deposited"
stare[4] = "20 cents or more deposited"

nickel = [stare[0], stare[1], stare[2], stare[3], stare[4], stare[1]]
dime1 = [stare[0], stare[2], stare[4], stare[2]]
dime2 = [stare[1], stare[3], stare[4], stare[2], stare[4]]

stareaInitiala=stare[1]
stareaCurenta = stareaInitiala
print ("Starea curenta: ", stareaCurenta)

while True:
    rel = input("0-nickel; 1-dime; 2-iesire din program. rel=: ")
    print(rel)
    if(rel == 0): 
        aux = nickel.index(currentState)
        stareaCurenta = nickel[aux+1]
        
    if(rel == 1):
        if (stareaCurenta in dime1):
            aux = dime1.index(stareaCurenta)
            stareaCurenta = dime1[aux+1]
        else: 
            aux = dime2.index(stareaCurenta)
            stareaCurenta = dime2[aux+1]
            
    if(rel == 2):
        print("exit")
        exit
        break        
    print ("Starea curenta: ", stareaCurenta) 


