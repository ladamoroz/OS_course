#!/bin/sh
gcc ex2.c -o ex2
(sysctl -a | grep machdep.cpu) | ./ex2 -a ex2.txt
