#!/bin/bash

#SBATCH --partition=guane_16_cores
#SBATCH --job-name=JVILLAMIZAR
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBACTH --cpus-per-task=16
#SBATCH --ntasks-per-node=1
#SBATCH --output=Salida_getInf_OpenMP_%j.out
#SBATCH --error=Salida_error_getInf_OpenMP_%j.err
#SBATCH -D /home/class/icp_2020_1/jevillamizarp/OpenMP


module load devtools/gcc/6.2.0

if [ -f SALIDA ]; then
        rm -r SALIDA
else
        gcc -fopenmp omp_mxm.c -o SALIDA
fi

if [ -n "$SLURM_CPUS_PER_TASK"]; then
        omp_threads=$SLURM_CPUS_PER_TASK
else
        omp_threads=1
fi

export OMP_NUM_THREADS=$omp_threads
./SALIDA


