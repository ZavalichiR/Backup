from Crypto.Hash import MD5
from hashlib import *

def get_file_checksum(filename):
    h=MD5.new()
    chunk_size = 8192
    with open(filename,'rb') as f:
        while True:
            text = f.read(chunk_size)
            if len(text) == 0:
                break
            else:
                h.update(text)
    return h.hexdigest()

def main():
    filename="fisier.txt"
    cod=get_file_checksum(filename)
    f=open(filename,'w')
    f.write(cod)
    f.close()
    print ("Textul a fost inlocuit cu codul")

main()
    

