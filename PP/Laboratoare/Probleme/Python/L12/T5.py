from hashlib import *

def main():
    h = md5() # md5 object

    filename = input("File name:")

    f = open(filename,'r')
    text = f.read()
    print(text)
    f.close()

   # h.update(text)
    f = open(filename,'w')
    f.write(h.hexdigest())
    f.close()

    f = open(filename,'r')
    print (f.read())
    f.close()

main()
