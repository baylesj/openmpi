#!/usr/bin/env bash

export LD_LIBRARY_PATH=/usr/local/lib

mpicc $1

scp a.out 192.168.1.100:~

mpirun -np 5 -H localhost,192.168.1.100 ./a.out -x LD_LIBRARY_PATH /usr/lib

