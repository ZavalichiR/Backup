import os
import random
from graphics import *

get={}
size={}
rect={}
def make_rect(get,size):
    return (Point(get[0],get[1]),Point(get[0]+size[0],get[1]+size[1]))

def main():

    win = GraphWin("Pietre",500,500)
    shape = Rectangle(Point(50,50), Point(20,20))
    shape.setOutline("dark_green")
    shape.setFill("dark")
    for i in range(100):
        p = win.getMouse()
        c = shape.getCenter()
        rect = make_rect((p.getX(),p.getY()),(10,10))
        shape = Rectangle(rect[0],rect[1])
        shape.setOutline("black")
        shape.setFill("black")
        shape.draw(win)
    win.close()
main()
