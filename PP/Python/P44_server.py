from __future__ import print_function
import socket

TCP_IP = "127.0.0.1"  # IP-ul (localhost)
TCP_PORT = 5005  # port-ul
BUFFER_SIZE = 1024  # marimea buffer-ului pentru datele transmise


def main():
    # deschidem socket-ul pentru receptie
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((TCP_IP, TCP_PORT))
    sock.listen(1)

    while True:
        # gestionam conexiunile
        print("Se asteapta conexiunea clientului partener...\n")
        conexiune, adresa = sock.accept()  # acceptam o conexiune

        while True:
            # receptionam date
            date = conexiune.recv(BUFFER_SIZE)
            if not date or date == "EXIT":
                print("Clientul a inchis conexiunea!")
                break
            print(conexiune.getpeername(), end="")
            print(" : %s" % date)

            # trimitem raspunsul
            print(sock.getsockname(), end="")
            raspuns = raw_input(" : ")
            conexiune.send(raspuns)

    conexiune.close();
    sock.close()

if __name__ == "__main__":
    main()
