#!/bin/bash

echo "Entering source directory..."
cd src
echo "[DONE]"
echo "Compiling library..."
make
#make -C ./src/ -f ./src/makefile
echo "[DONE]"
cd ..
echo "Copying library..."
cp src -r /usr/include/libido
echo "[DONE]"
