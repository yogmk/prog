import socket, sys

host = sys.argv[1]
file = sys.argv[2]

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((host, 80))

fd = sock.makefile('r', 0)

fd.write (" GET "+file+" HTTP/1.0\n\n")

buff = fd.readlines()

for line in buff:
    print line

    