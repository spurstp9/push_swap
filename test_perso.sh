#!/bin/bash

if (( $# != 2 )) ; then
	echo "Usage : script_test stack_length number_of_tests"
	exit 1 
fi

let "total = 0"
for (( i=0 ; i<$2 ; i++ )) ;
do
	ARG=`ruby -e "puts (-9999..9999).to_a.sort{ rand() - 0.5 }[0..($1 - 1)].join(' ') "`
	PS_RESULT="`./push_swap $ARG`"
	RESULT="`echo ${PS_RESULT} | tr " " "\n" | wc -l | bc`"
	let "total += RESULT"
	CHECKER_RESULT="`./push_swap $ARG | ./checker $ARG`"
	if (( $CHECKER_RESULT == "OK")) ; then
		CHECKER_RESULT="✓"
	else
		CHECKER_RESULT="⨯"
	fi
    echo "${RESULT}		${CHECKER_RESULT}"
done

let "average = total / $2"

echo "Average: ${average}"
