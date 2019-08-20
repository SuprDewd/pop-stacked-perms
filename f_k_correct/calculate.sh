#!/usr/bin/env bash
K=$1

mkdir -p output
./dfa $K > output/dfa_${K}.txt
./DFA_minimizer < output/dfa_${K}.txt > output/dfa_${K}_min.txt

python dfa_to_gf.py $K < output/dfa_${K}_min.txt > tmp.sage
sudo docker run -ti -v $(pwd):/home/sage/tmp sagemath/sagemath sage ./tmp/tmp.sage
rm -f tmp.sage tmp.sage.py

