from __future__ import print_function
import socket

SERVER_IP = "127.0.0.1"  # IP-ul (localhost)
SERVER_PORT = 5005  # port-ul
BUFFER_SIZE = 1024  # marimea buffer-ului pentru datele transmise


def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # ceam socket-ul
    sock.connect((SERVER_IP, SERVER_PORT))
    while True:
        # trimitem mesaj catre server
        print(sock.getsockname(), end="")
        mesaj = raw_input(" : ")
        sock.send(mesaj)
        if mesaj == "EXIT":
            break

        # primim raspuns de la server
        raspuns = sock.recv(BUFFER_SIZE)
        if raspuns == "EXIT":
            print("Serverul a inchis conexiunea!")
            break
        print(sock.getpeername(), end="")
        print(" : %s" % raspuns)
    sock.close()

if __name__ == "__main__":
    main()
