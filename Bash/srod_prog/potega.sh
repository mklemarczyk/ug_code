$bash

function potega {
	if [ $2 -eq 1 ]
	then
		echo $1
	else
		mniejszy=$[$2-1]
		wynik=$[$1*`potega $1 $mniejszy`]
		echo $wynik
	fi
}

function potega2 {
	wynik=1
	for ((i=0; i<$2; i++)) do
		wynik=$(($wynik*$1))
	done
	echo $wynik
}

function potega3 {
	wynik=1
	wyk=$(($1*$1))
	pot2=$(($2/2))
	mod=$(($2%2))
	if [ $mod -eq 0 ] 
	then
		wynik=$[`potega $wyk $pot2`]
		echo $wynik
	else
		wynik=$((`potega $wyk $pot2`*$1))
		echo $wynik
	fi
}

function modulo {
	wynik=`potega2 $1 $2`
	while [ $wynik -ge $3 ]
	do
		wynik=$(($wynik-$3))
	done
	echo $wynik
}

function modulo2 {
	wynik=`potega2 $1 $2`
	iloraz=$(($wynik/$3))
	wynik=$(($wynik-$iloraz*$3))
	echo $wynik
}

function modulo3 {
	wynik=`potega2 $1 $2`
	wynik=$(($wynik%$3))
	echo $wynik
}

echo "Wynik: `potega $1 $2`"
echo "Wynik2: `potega2 $1 $2`"
echo "Wynik3: `potega3 $1 $2`"
echo "Modulo: `modulo $1 $2 $3`"
echo "Modulo2: `modulo2 $1 $2 $3`"
echo "Modulo3: `modulo2 $1 $2 $3`"
