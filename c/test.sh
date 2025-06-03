#!/bin/bash

# set -x
test_number=0;
ptest () {
	test_number=$(($test_number + 1))
	echo $test_number
	./push_swap $1 &> out
	res=$(cat out | ./checker_linux $1 2>&1)
	if [[ "$2" == 'err' ]]; then
		if [[ "$(cat out)" != "Error" ]]; then
			echo Test $test_number FAILED, expected error
		fi
	else
		if [[ "$res" != "OK" && "$res" != "" ]]; then
			echo Test $test_number $1 FAILED, expected OK, Checker got KO
		fi
		if (( $(cat out | wc -l) > $2 ));  then
			echo Test $test_number FAILED, expected "<= $2", got $(cat out | wc -l)
		fi
	fi
}

ctest () {
	test_number=$(($test_number + 1))
	echo checker_test: $test_number

	res=$(echo -en $1 | sed "s/, /\n/g" | ./checker_linux $2 2>&1)

	if [[ "$res" != "$res2" || "$res" != "$3" ]]; then
		echo CHECKER FAILED ON Test $test_number \($1\) custom checker FAILED
		echo $res != $res2
	fi
}

ctest "sa, pb, rrr\n" "0 9 1 8 2 7 3 6 4 5" KO
ctest "" "0 1 2" OK
ctest "pb, ra, pb, ra, sa, ra, pa, pa\n" "0 9 1 8 2" OK

ptest "" 0
ptest "1 3 2" 2
ptest "1 3 22123" 0
ptest "1 3 f22123" err
ptest "1 3 --22123" err
ptest "1 3 +2147483647" 0
ptest "1 3 +2147483648" err
ptest "1 3 -2147483648" 2
ptest "1 3 -2147483649" err

ptest "42" 0
ptest "2 3" 0
ptest "0 1 2 3" 0
ptest "0 1 2 3 4 5 6 7 8 9" 0
ptest "0 3 4 5 6 9" 0

ptest "2 1 0" 2
ptest "1 4 0" 2
ptest "2 9 1" 2
ptest "3 4 1" 2

ptest "1 5 2 4 3" 7
for i in $(seq 1 500); do
	ptest "$(seq 1 5 | shuf)" 12
done

for i in $(seq 1 500); do
	ptest "$(seq 1 100 | shuf)" 700
done

for i in $(seq 1 500); do
	ptest "$(seq 1 500 | shuf)" 5500
done
