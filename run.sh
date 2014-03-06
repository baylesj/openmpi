#!/usr/bin/env bash

mpirun -np 5 -H localhost,slave1 ./a.out -x LD_LIBRARY_PATH /usr/lib

