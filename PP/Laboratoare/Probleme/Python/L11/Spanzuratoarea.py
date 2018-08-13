import os
import random
from graphics import *

def cls():
    os.system("clear")

win = GraphWin("Test", 500, 650)
start_x = 200
desen  = {}
obiect = Circle(Point(start_x,200),50)
desen[0] = obiect
 
poz = 1
for ln in ((0, 150,    0, 100),
           (0, 100,    -100, 100),
           (-100, 100, -100, 500),
           (0, 250,    0, 380),
           (0, 380,    -50, 450),
           (0, 380,    50, 450),
           (0, 300,    -50, 380),
           (0, 300,    50, 380)):
    obiect = Line(Point(start_x+ln[0], ln[1]), Point(start_x+ln[2], ln[3]))
    desen[poz] = obiect
    poz += 1

def Joc():
    desen[1].draw(win)
    desen[1].setWidth(2)
    desen[2].draw(win)
    desen[2].setWidth(2)
    desen[3].draw(win)
    start=0
    cuvinte = ["Zava","Alex","PP","mancare","vacanta","soare"]
    rel = True 
    while rel: 

           cuvantDeGhicit = random.choice(cuvinte) #alege random
           litere = "-" * len(cuvantDeGhicit) #seteaza - - - -...
           dejaSpus = set()
           incercari = 7 
           print(" ".join(litere)) # afiseaza ------...
 
           gasit = False
           while not gasit and incercari > 0:
               
               litera = input("Ghiceste o litera: ") 
               if litera in cuvantDeGhicit: #daca litera se afla in cuvantDeGhicit
                   dejaSpus.add(litera) #litera se adauga ladejaSpus
                   litere= "".join([char if char in dejaSpus else "-" for char in cuvantDeGhicit])
                   if litere == cuvantDeGhicit:
                       gasit = True
               else:
                   incercari -= 1
                   print("Mai aveti", incercari, "incercari.")
                   
                   if (start==0):
                       desen[start].draw(win)
                       start=1
                       poz=4
                   else:
                            if (poz == 9):
                                obiect = Line(Point(50,50),Point(300,500))
                                obiect2= Line(Point(50,500),Point(300,50))
                                obiect.setWidth(4)
                                obiect2.setWidth(4)
                                obiect.draw(win)
                                obiect2.draw(win)
                            else:
                                desen[poz].draw(win)
                                poz+=1
               print("\n------------------------------------------------------------\n")
               print(" ".join(litere))

           if(gasit==True):
                print("Ati castigat")
           else:
                print("Ati pierdut")
                      
           rel = (input("Reluati jocul? [y/n]: ").lower() == 'y') # asks if you want to go again -- changes it to lower cap
           import os
           clear = lambda: os.system('cls')
           clear()


Joc()
win.close()


