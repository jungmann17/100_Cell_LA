#!/bin/bash

#SBATCH -J 100_Cell_LA
#SBATCH -o results-%j.out
#SBATCH -p RC 
#SBATCH -t 0-05:00
#SBATCH -N1
#SBATCH -n10

module load openmpi/openmpi-2.0.1
module list

echo "$(hostname), reporting for duty."
echo "Starting 100 Cell LA Model at $(date)"

source /group/rcworkshop1/neuron_python/bin/activate_nrn
which python

mpirun -np $SLURM_NTASKS nrniv -python -mpi 100_Cell_LA.py

echo "Program complete..."
deactivate
