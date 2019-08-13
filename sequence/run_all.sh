#!/usr/bin/env bash

source ./primes.sh
for prime in "${primes[@]}"; do
    echo "prime $prime"
    time ./sequence_mod $prime > sequence_${prime}.txt
done
