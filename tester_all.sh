#!/bin/bash
LOG_NAME="log.txt"
LIMIT=$1;
COUNT=1;

echo -e "==Push Swap Tester==\n" > $LOG_NAME

echo "==3 Valores==" >> $LOG_NAME
for (( i=1; i <= 5; ++i ))
do
    NUMBER=$(shuf -i 1-3 | sed -e :a  -e 'N;s/\n/ /;ta');
    TEST=$(./push_swap "$NUMBER" | ./checker_linux "$NUMBER");
    MOVIMENTS=$(./push_swap "$NUMBER" | wc -l);
    SIZE="3";
    (
        echo "TESTE: $COUNT";
        echo "Valores: $NUMBER";
        echo "Resultado: $TEST";
        echo "Movimentos: $MOVIMENTS/$SIZE";
        echo "";
    ) >> $LOG_NAME
    COUNT=$((COUNT+1));
done

echo "==5 Valores==" >> $LOG_NAME
for (( i=1; i <= 5; ++i ))
do
    NUMBER=$(shuf -i 1-5 | sed -e :a  -e 'N;s/\n/ /;ta');
    TEST=$(./push_swap "$NUMBER" | ./checker_linux "$NUMBER");
    MOVIMENTS=$(./push_swap "$NUMBER" | wc -l);
    SIZE="12";
    (
        echo "TESTE: $COUNT";
        echo "Valores: $NUMBER";
        echo "Resultado: $TEST";
        echo "Movimentos: $MOVIMENTS/$SIZE";
        echo "";
    ) >> $LOG_NAME
    COUNT=$((COUNT+1));
done

echo "==100 Valores==" >> $LOG_NAME
for (( i=1; i <= 10; ++i ))
do
    NUMBER=$(shuf -i 1-100 | sed -e :a  -e 'N;s/\n/ /;ta');
    TEST=$(./push_swap "$NUMBER" | ./checker_linux "$NUMBER");
    MOVIMENTS=$(./push_swap "$NUMBER" | wc -l);
    SIZE="700";
    (
        echo "TESTE: $COUNT";
        echo "Valores: $NUMBER";
        echo "Resultado: $TEST";
        echo "Movimentos: $MOVIMENTS/$SIZE";
        echo "";
    ) >> $LOG_NAME
    COUNT=$((COUNT+1));
done

echo "==500 Valores==" >> $LOG_NAME
for (( i=1; i <= 10; ++i ))
do
    NUMBER=$(shuf -i 1-500 | sed -e :a  -e 'N;s/\n/ /;ta');
    TEST=$(./push_swap "$NUMBER" | ./checker_linux "$NUMBER");
    MOVIMENTS=$(./push_swap "$NUMBER" | wc -l);
    SIZE="5500";
    (
        echo "TESTE: $COUNT";
        echo "Valores: $NUMBER";
        echo "Resultado: $TEST";
        echo "Movimentos: $MOVIMENTS/$SIZE";
        echo "";
    ) >> $LOG_NAME
    COUNT=$((COUNT+1));
done