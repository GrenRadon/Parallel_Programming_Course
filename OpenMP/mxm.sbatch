#!/bin/bash

#SBATCH --partition=guane_24_cores  # Partition name - The names are obtained with the sinfo command
#SBATCH --job-name=mxm_Jv           # Name of the task to be executed - can be any
#SBATCH --nodes=1                   # Number of nodes to use
#SBATCH --ntasks=1		    # Number of tasks to execute
#BACTH --cpus-per-task=16           # Number of cores assigned to each task
#SBATCH --ntasks-per-node=1         # Total number of tasks to execute per node
#SBATCH --output=output_mxm_%j.txt  # Output file containing the results of the execution
#SBATCH --error=error_mxm_%j.err    # File containing runtime errors 
#SBATCH -D /home/class/icp_2020_1/jevillamizarp/OpenMP #Directory where we have our project


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



