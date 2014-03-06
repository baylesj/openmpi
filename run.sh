#!/usr/bin/env bash

mpirun -pernode -H localhost,slave1 ./a.out -x LD_LIBRARY_PATH /usr/lib

