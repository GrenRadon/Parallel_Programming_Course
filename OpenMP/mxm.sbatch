#!/bin/bash

#SBATCH --partition=guane_24_cores
#SBATCH --job-name=mxm_Jv
#SBATCH --nodes=1
#SBATCH --ntasks=1
#BACTH --cpus-per-task=16
#SBATCH --ntasks-per-node=1
#SBATCH --output=output_mxm_%j.txt
#SBATCH --error=error_mxm_%j.err
#SBATCH -D /home/class/icp_2020_1/jevillamizarp/OpenMP


module load devtools/gcc/6.2.0

if [ -f SALIDA ]; then
        rm -r SALIDA
fi

gcc -fopenmp omp_mxm.c -o SALIDA

if [ -n "$SLURM_CPUS_PER_TASK"]; then
        omp_threads=$SLURM_CPUS_PER_TASK
else
        omp_threads=1
fi

export OMP_NUM_THREADS=$omp_threads
./SALIDA 45000 45000 45000



