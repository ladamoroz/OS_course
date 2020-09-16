#!/bin/bash
if test ! -f data
    then
        echo 0 > data
fi
if ln data data.lock
    then
    for i in `seq 1 1000`;
    do
        n=`tail -1 data`
        ((n += 1))
        echo $n >> data
    done
    
    rm data.lock
fi




#if test ! -f data
#    then
#        echo 0 > data
#fi
#for i in `seq 1 1000`;
#do
#    n=`tail -1 data`
#    ((n += 1))
#    echo $n >> data
#done

