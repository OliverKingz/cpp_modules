#!/bin/bash

echo "Starting tester made by raperez-/RaulPerezDEV..."
cd ../ex02
make re
cd ../ex02_tester
../ex02/dream_job > my.log
echo x >> my.log
g++ comparer.cpp -o comparer
./comparer
rm comparer
cd ../ex02
make fclean
echo "Tester finished!"