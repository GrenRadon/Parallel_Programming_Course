## Local execution steps:

Firstly, we must launch our compiler using the gcc instruction as follow below:

- gcc -fopenmp omp_mxm.c -o /Extra/executions/SalidaXXX

Where:

* gcc-> Our compiler version of C language.
* fopenmp ->A flag provided to load correctly openmp libraries needed to our purposes.
* SalidaXXX -> An output once we compile correctly our code. XXX represents the number of compilation we are. 
* omp_mxm.c-> An implementation using omp directives.

Lastly, once we get our outcome, it's just to execute it by typing the next line in the relative path: 
./SalidaXX


## Guane execution steps:  

To execute properly our code in a Guane node we must log in first, once inside the front-end, we gotta enter to a guane node assigned randomly by typing "ssh guane".

All setting are contained in the sbatch file so it's just to launch it by typing"sbatch mxm.sbatch". It's extremely necessary to note that we have to modify the .sbatch file at the very end since according to the scaled part,we can change it by changing the arguments, some examples of this are: "./SALIDA 100 100 100", "./SALIDA 30000 30000 30000"

## Future improvements: 

We will be able to improve the Pragmas regions by using numerical methods or algebra techniques. For more information visit the next [wikipedia's link](https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm).

## Additional information:

We used as tutorial guide the [OpenMP online page](https://computing.llnl.gov/tutorials/openMP/#ParallelRegion). This source was truly important at the moment of building our implementation in OpenMP. 




