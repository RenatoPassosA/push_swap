#!/bin/bash
NUM=$(shuf -i 1-$1 | sed -e :a  -e 'N;s/\n/ /;ta')
./push_swap "$NUM" | ./checker_linux "$NUM";
echo "$NUM" > "test.txt"