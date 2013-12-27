$bash

#Zad 1
cat plik.txt | grep [a-zA-Z]
cat plik.txt | grep .

#Zad 2
cat pl* | grep ^[0-9]

#Zad 3
grep -l "^.\{8\}[r]" pl*

#Zad 4
cat /etc/passwd | grep bash

#Zad 5
cat plik.txt | grep . | egrep "^(([M]{0,3})?(([D]?[C]{0,3})|([C][D])|([C][M]))?([C]{0,3})?(([L]?[X]{0,3})|([X][L])|([X][C]))?([X]{0,3})?(([V]?[I]{0,3})|([I][V])|([I][X]))?)$"
