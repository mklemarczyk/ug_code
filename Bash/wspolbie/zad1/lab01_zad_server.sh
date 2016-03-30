#!/bin/bash

srcf=dane.txt
dstf=wyniki.txt

while [ 1 ]; do
	if [ -e $srcf ]; then
		p=`head -n1 $srcf`
		if [ ! -z "$p" ]; then
			rm $srcf
			echo $(expr $p + $p) > $dstf
		fi
	fi
done
