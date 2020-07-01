#!/bin/bash

#SBATCH --partition=normal
#SBATCH --job-name=G_INFO_JVILLAMIZAR
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBACTH --cpus-per-task=8
#SBATCH --ntasks-per-node=1
#SBATCH --output=Salida_getInf_OpenMP_%j.out
#SBATCH --error=Salida_error_getInf_OpenMP_%j.err
#SBATCH -D /home/class/icp_2020_1/jevillamizarp/getEnvInfo
 

module load devtools/gcc/6.2.0

if [ -f getEnvINFO ]; then
	rm -r getEnvINFO
else
	gcc -fopenmp omp_getEnvInfo.c -o getEnvINFO
fi

if [ -n "$SLURM_CPUS_PER_TASK"]; then
	omp_threads=$SLURM_CPUS_PER_TASK
else
       	omp_threads=1
fi

export OMP_NUM_THREADS=$omp_threads
./getEnvINFO

