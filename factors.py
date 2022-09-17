#!/usr/bin/python3

   
from sys import argv
if len(argv) != 2:
    exit();
file = open(argv[1], 'r')
for line in file:
    nbr = int(line)
    i = 2
    while True:
        if nbr % i == 0:
            print("{}={}*{}".foramt(nbr, (nbr / i), i))
file.close()
