from ast import If
import socket
from threading import Thread
from time import sleep


# Multithreaded Python server
class ClientThread(Thread):

    def __init__(self, ip, port):
        Thread.__init__(self)
        self.ip = ip
        self.port = port
        print("Incoming connection from " + ip + ":" + str(port))

    def run(self):
        while True:
            try:
                data = conn.recv(2004)
                if len(data) == 0:
                    break
                print("Data: ", data)
                print(type(data))
                start = data.find(b'Time=') + 5
                print("Ok Start")
                end = data.find(b':', start)
                print("Ok End")
                waktu = int(data[start:end])
                print(waktu)

                if waktu > 5:
                    if waktu < 17:
                        condition = "led-off"
                    elif waktu > 17:
                        condition = "led-on"
                elif waktu < 5:
                    if waktu > 0:
                        condition = "led-on"
                print(condition)
                conn.send(condition.encode("utf8"))  # echo
            except Exception as e:
                print(e)
                break
           # sleep(0, 25)


TCP_IP = "0.0.0.0"
TCP_PORT = 2004
BUFFER_SIZE = 20

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcpServer.bind((TCP_IP, TCP_PORT))
threads = []

while True:
    tcpServer.listen(4)
    print("Server started on " + TCP_IP + " port " + str(TCP_PORT))
    (conn, (ip, port)) = tcpServer.accept()
    newthread = ClientThread(ip, port)
    newthread.start()
    threads.append(newthread)

for t in threads:
    t.join()
