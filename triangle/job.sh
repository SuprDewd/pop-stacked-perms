#!/usr/bin/env bash
#SBATCH --job-name=popstacked
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --array=0-96

cd /users/home/bjarkig12/popstacked_triangle

source ./primes.sh
prime=${primes[SLURM_ARRAY_TASK_ID]}

echo "prime $prime"

for i in $(seq 1 4); do
    # Hack to deal with NFS issue
    sleep $(( RANDOM % 10 ))
    echo "trying"
    time ./triangle_mod $prime > triangle_${prime}.txt || continue
    break
done

echo "done"

