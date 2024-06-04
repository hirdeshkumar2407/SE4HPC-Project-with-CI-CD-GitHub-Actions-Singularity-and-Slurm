#!/bin/bash

#SBATCH --job-name=calc_script  # Job name
#SBATCH --output=matrix_multiplication.out.log  # Capture standard output
#SBATCH --error=matrix_multiplication.err.log   # Capture standard error
#SBATCH --partition=short          # Queue (partition) to submit to
#SBATCH --time=0-00:30           # Maximum wallclock time (30 seconds)
#SBATCH --cpus-per-task=2          # Allocate 1 CPU core
#SBATCH --mem=1G                   # Allocate 1 GB of memory
#SBATCH --nodes=1                  # Allocate 1 node
#SBATCH --ntasks=2                 # Allocate 1 task

# Perform calculation
echo "Performing calculation..."
singularity exec matrix_multiplication.sif mpirun -np 2 /usr/src/matrix_multiplication/main
sleep 30  # Simulate matrix  computation (replace with your actual calculation)

# Print result
echo "Calculation complete!"