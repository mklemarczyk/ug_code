#!/bin/bash

srcf=dane.txt
dstf=wyniki.txt

if [ -e $dstf ]; then
	rm $dstf
fi

echo "Podaj liczbe"
read p
echo $p > $srcf

while [ ! -e $dstf ]; do :
done

p=`head -n1 $dstf`
rm wyniki.txt

if [ ! -z "$p" ]; then
	echo "Twoj wynik $p"
else
	echo "Nie ma wyniku"
fi
