#!/bin/bash

for dirs in ./*/; do
	cd $dirs
	
	currentDir=$(pwd)
	echo "Apagando diretorio de testes em $currentDir" 

	rm -rf testes

	for executavel in ./*.out; do
		echo "Apagando executavel $executavel em $currentDir"
		rm -rf executavel
	done

	cd ..
done
