$bash

#Pol 1
find ~ -maxdepth 1 -type f -mtime -10 -printf "%f\n"

#Pol 2
find / -name "*conf*" -type f -printf "%f\n"

#Pol 3
find ~ -type f -atime +20

#Pol 4
find /etc \( -type d -not -empty \) -or \( -type f -name "a*" \)

#Pol 5
find . -type f -name "x??" -delete
#rm `find . -type f -name "x??" -printf "%p "`

#Pol 6
mkdir `date +"%Y-%m-%d"`
