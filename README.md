# SE4HPC Project with CI/CD, GitHub Actions, Singularity, and Slurm
###  Project Mission
In the world of High-Performance Computing, the challenge is not just writing fast code, but deploying it reliably and efficiently on complex supercomputer environments. This project, for the "Software Engineering for HPC" course at Politecnico di Milano, was designed to solve that exact problem.
As the project lead, I guided our team in architecting a full, end-to-end CI/CD pipeline specifically for HPC applications. Our mission was to bring modern DevOps best practices to the world of scientific research, using industry-standard tools like GitHub Actions, Singularity containers, and the Slurm workload manager.
The result is a fully automated system that can build, test, containerize, and deploy a parallel MPI application directly onto a supercomputer like Galileo100. This project demonstrates a crucial and rare skill: the ability to bridge the gap between agile software development and the rigorous demands of high-performance scientific computing.


### The Team

This project's success was a result of a talented and collaborative team effort, with invaluable guidance from our teaching staff.

#### Contributors:

[Hirdesh Kumar](https://github.com/hirdeshkumar2407)

[Nadah Khaled](https://github.com/nadahkhaledd)

[Milica Sanjevic](https://github.com/milicasanjevic)

### Guidance:

[Professor Elisabetta Di Nitto](https://github.com/dinitto)

[Teacher Assistant Simone Reale](https://github.com/SimoneReale)

### Features
- Parallel Matrix Multiplication: Utilizes MPI for parallel computation.
- CI/CD Pipeline: Automates build, test, and release processes with GitHub Actions.
- Containerization: Employs Singularity for containerizing the application.
- Cluster Execution: Automates job submission to a Slurm cluster.
- C++ Implementation: Core application developed in C++.
- Makefile Support: Uses make for build automation.

## Repository Structure
- .github/workflows: Contains GitHub Actions workflows.
- include: Header files.
- lib: Library files.
- out-from-slrum-cluster: Outputs from the Slurm cluster.
- src: Source code.
- test: Test cases.
- Singularity.def: Singularity definition file.
- Makefile: Makefile for building the project.
- build.sh: Build script.
- job.sh: Slurm job submission script.
- matrixA.txt, matrixB.txt: Input matrices.

### Getting Started
#### Prerequisites
Git
GitHub Account
MPI Library
Singularity
Access to a Slurm cluster
C++ Compiler
make utility
##### Setup
#### Clone the repository:

```
git clone https://github.com/hirdeshkumar2407/SE4HPC-Project-with-CI-CD-GitHub-Actions-Singularity-and-Slurm/.git

cd My-Project--SE4HPC_project_part2

## Build the application:

make
```

#### Define the Singularity container:
Ensure Singularity.def is correctly set up to containerize the application.

#### Running Tests
Push changes to the repository to trigger the GitHub Actions workflow, which will build and test the application automatically.

#### Deploying to Slurm
Prepare Slurm job script:
Edit job.sh as needed.

#### Transfer files to cluster:
scp job.sh user@cluster:/path/to/job.sh
scp matrixA.txt matrixB.txt user@cluster:/path/to/
scp my_container.sif user@cluster:/path/to/

#### Submit job to Slurm:

```
sbatch job.sh
```

### CI/CD Pipeline
The CI/CD pipeline includes the following steps:

Build and Test: Automatically builds and tests the application on code push.

Containerize: Builds a Singularity container.

Deploy: Transfers the container and job script to the Slurm cluster and submits the job.



