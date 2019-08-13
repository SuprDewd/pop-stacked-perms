#!/usr/bin/env bash

source ./primes.sh
for prime in "${primes[@]}"; do
    echo "prime $prime"
    time ./triangle_mod $prime > triangle_${prime}.txt
done

