#!/bin/sh

# Super clean that removes useless files and directories

make clean
rm -f *~
rm -f Makefile
rm -f crowd_simulation
rm -r build/

cd src
rm -f *~
cd ..

cd scenes
rm -f *~
cd ..

