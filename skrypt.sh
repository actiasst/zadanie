#!/bin/bash

a=`./p2.out`

b=`echo $a | aspell -a | wc -w`

if [ $b == 10 ]
then
echo "Wyraz wystepuje w jezyku polskim"
else
echo "Wyraz nie wystepuje w jezyku polskim lub jest blednie napisany"
fi
