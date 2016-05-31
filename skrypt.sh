#!/bin/bash

d=`date +%u`

if [ $d == 5 ] || [ $d == 6 ] || [ $d == 7 ]

then

a=`./p2.out`

b=`echo $a | aspell -a | wc -w`

if [ $b == 10 ]

then

echo "Wyraz wystepuje w jezyku polskim"

else

echo "Wyraz nie wystepuje w jezyku polskim lub jest blednie napisany"

fi

fi
