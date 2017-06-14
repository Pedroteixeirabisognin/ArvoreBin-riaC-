#!/bin/bash


for i in $(seq $(($1-1)) -1 1)
do

	for j in $(seq $i)
	do
		for k in $(seq $1)
		do

		printf " "		

		done

		printf "*"


		for k in $(seq $1)
		do

		printf " "		

		done
	done

	echo

done
for i in $(seq $1)
do

	for j in $(seq $i)
	do
		for k in $(seq $(($1-1)) -1 1)
		do

		printf " "		

		done

		printf "*"


		for k in $(seq $(($1-1)) -1 1)
		do

		printf " "		

		done
	done

	echo

done



