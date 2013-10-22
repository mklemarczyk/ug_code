$bash

#Pol 1
mkdir temp;
mkdir temp/dom;
mkdir temp/nauka;
mkdir temp/nauka/c;
mkdir temp/nauka/logo;
mkdir temp/nauka/pascal;
mkdir temp/praca;
mkdir temp/praca/dokumenty;
mkdir temp/praca/zlecenia;
mkdir temp/praca/zlecenia/niezrealizowane;
mkdir temp/praca/zlecenia/zrealizowane;

#Pol 2
cd temp/dom;
mkdir wazne\-sprawy;

#Pol 3
cd wazne\-sprawy;
touch rachunki.txt

#Pol 4
cp rachunki.txt ../../praca/zlecenia/zrealizowane;

#Pol 5
cd ../../praca/zlecenia/zrealizowane;
mv rachunki.txt wykonano.txt;

#Pol 6
echo "Moja teksta" > wykonano.txt;
split wykonano.txt -b5;

#Pol 7
cd ../../../nauka/logo;
cp ../../praca/zlecenia/zrealizowane/x* ../../praca/dokumenty/;

#Pol 8
cd ../../praca/dokumenty;
cat x* > odtworzono.txt;

#Pol 9
cd ../../dom/wazne\-sprawy;
diff -usr ../../praca/dokumenty/odtworzono.txt ../../praca/zlecenia/zrealizowane/wykonano.txt;

#Pol 10
cal -3;
cal -3 11 2012;
cal -3 | cut -c 1-44;
cal -3 | cut -c 26-67;

#Pol 11
date "+%A" -d "25 may 1975"
