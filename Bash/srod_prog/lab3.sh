$bash

#Pol 1
more -5 -d -p /etc/passwd

#Pol 2 ?
cat tekst1.txt > tekst3.txt; cat >> tekst3.txt; cat tekst2.txt >> tekst3.txt

#Pol 3
head -n5 -q ~/*.txt

#Pol 4
head -n5 /etc/passwd | tail -n3

#Pol 5
tail -n7 /etc/passwd | head -n3 | tac

#Pol 6
cat /etc/passwd | tr "\n" " "

#Pol 7
cat /etc/passwd | tr -c "[a-zA-Z]" "\n" | tr -s "\n"

#Pol 8
#Zlicza katalogi zamiast plikow :) 
#tree -d /etc | tail -n1
#Roz 1
tree /etc | tail -n1 | cut -d , -f 2
#Roz 2
find -P /etc -type f 2> /dev/null | wc -l
#Roz 3
ls /etc -laR 2> /dev/null | grep ^- | wc -l

#Pol 9
head -n3 -q /etc/passwd | wc -c

#Pol 10 *
#Roz 1
head -5 -q `file ~/* | grep text$ | cut -d : -f 1 | tr -c "[a-zA-Z0-9.~/]" " "`
#Roz 2
file ~/* | grep text$ | cut -d : -f 1 | tr -c "[a-zA-Z0-9.~/]" " " | xargs head -5 -q
