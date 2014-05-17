from time import sleep

str = "now you know how to sleep in Python!"

words = str.split()

for word in words:
    sleep(0.30)
    print word

sleep(0.30)


