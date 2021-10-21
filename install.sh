#!/bin/bash

rm -rf /usr/include/libido
cp src -r /usr/include/libido
make -C /usr/include/libido -f /usr/include/libido/makefile
#cd /usr/include/libido
#make
