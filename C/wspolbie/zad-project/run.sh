#!/bin/bash

gcc game.c -o game -lX11 -lpthread -lm

if [ "$#" -lt 1 ]; then
	echo "Za malo parametrow"
	echo "uzyj ./run.sh <adres_ip>"
	echo "uzyj ./run.sh <adres_ip> -s"
elif [ "$#" -ge 3 ]; then
	echo "Za duzo parametrow"
	echo "uzyj ./run.sh <adres_ip>"
	echo "uzyj ./run.sh <adres_ip> -s"
else
./game $1 $2
fi
