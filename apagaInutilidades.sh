#!/bin/bash

for dirs in ./*/; do
	cd $dirs
	
	currentDir=$(pwd)
	echo "Apagando diretorio de testes em $currentDir" 

	rm -rf testes

	cd ..
done
