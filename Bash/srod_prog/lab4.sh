$bash

#lPol 1
ls -1p | grep -v / | tr [:lower:] [:upper:]

#Pol 2
ls -lp | grep -v / | tr -s " " | cut -d " " -f 1,5,9-

#Pol 3
ls -1Sp | grep -v /

#Pol 4
sort -t: -k3 -n -r /etc/passwd

#Pol 5
sort -nr -t: -k4 -k3 /etc/passwd

#Pol 6
find / -printf "%u\n" 2>/dev/null | sort |  uniq -c

#Pol 7
find / -printf "%m\n" 2>/dev/null | sort |  uniq -c


#ls -l > lsout.txt                           #  1
#Odp: Zapisuje liste plikow w pliku lsout.txt

#ls -la >> lsout.txt                         #  2
#Odp: Dopisuje do pliku lsout.txt liste plików włączając w to pliki ukryte

#ps >> psout.txt                             #  3
#Odp: Dopisuje do pliku psout.txt listę bierzących procesów

#free -m >> ~/wynik                          #  4
#Odp: Dopisuje do pliku wynik w katalogu domowym, informacje na temat zajętości miejsca na dysku w megabajtach.

#kill -1 1234 > killout.txt 2>killerr.txt    #  5
#Odp: 

#kill -1 1234 > killout.txt 2>&1             #  6
#Odp: 

#kill -1 1234 > /dev/null 2>&1               #  7
#Odp: 

#sort psout.txt > pssort.txt                 #  8
#Odp: Sortuje plik psout.txt i zapisuje wynik do pliku pssort.txt

#ps | sort > pssort.txt                      #  9
#Odp: Zapisuje do pliku psout.txt posortowaną listę bierzących procesów

#cat lsout.txt | sort > lssort.txt           # 10
#Odp: Sortuje plik lsout.txt i zapisuje wynik do pliku lssort.txt

#who | sort | more                           # 11
#Odp: 

#who | sort | less                           # 12
#Odp: 

#find -type f | wc                           # 13
#Odp: 

#find -type f -print0 | wc --files0-from=-   # 14
#Odp: 

