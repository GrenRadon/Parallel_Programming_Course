## **Local Execution steps:**

Firstly, we must launch our compiler using the gcc instruction as follow below: gcc -fopenmp omp_mxm.c -o SalidaXXX

Where:

*gcc-> Our compiler version of C language
*fopenmp ->A flag provided to load correctly openmp libraries needed to our purposes.
*SalidaXXX -> Which is our outcome once we compile correctly our code. XXX represents the number of compilation we are. 
*omp_mxm.c-> Our implementation using omp directives.

Once we get our outcome is just to execute it by typing the next line: 
./SalidaXX


Guane-1 Execution steps:  



Local outcomes: 

Matrix B is 100 by 100
  Matrix C is 100 by 100
  Matrix A will be 100 by 100

  Number of floating point operations = 2000000
  Estimated CPU time is 0.000769 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.009790      204.290092
  IKJ           0.004279      467.398925
  JIK           0.004020      497.512438
  JKI           0.003817      523.971706
  KIJ           0.004028      496.524330
  KJI           0.003879      515.596803

MXM:
  Normal end of execution.

Matrix B is 200 by 200
  Matrix C is 200 by 200
  Matrix A will be 200 by 200

  Number of floating point operations = 16000000
  Estimated CPU time is 0.006154 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.040349      396.540187
  IKJ           0.041414      386.342783
  JIK           0.037396      427.853246
  JKI           0.031844      502.449441
  KIJ           0.040963      390.596392
  KJI           0.033057      484.012463

MXM:
  Normal end of execution.

Matrix B is 500 by 500
  Matrix C is 500 by 500
  Matrix A will be 500 by 500

  Number of floating point operations = 250000000
  Estimated CPU time is 0.096154 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.563325      443.793547
  IKJ           0.700646      356.813569
  JIK           0.632634      395.173197
  JKI           0.509771      490.416285
  KIJ           0.698384      357.969255
  KJI           0.522783      478.209888

MXM:
  Normal end of execution.

Matrix B is 1000 by 1000
  Matrix C is 1000 by 1000
  Matrix A will be 1000 by 1000

  Number of floating point operations = 2000000000
  Estimated CPU time is 0.769231 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           4.922978      406.258163
  IKJ          15.439746      129.535810
  JIK           7.132382      280.411229
  JKI           4.312295      463.790163
  KIJ          15.707791      127.325351
  KJI           4.030941      496.162062

MXM:
  Normal end of execution.


Matrix B is 2000 by 2000
  Matrix C is 2000 by 2000
  Matrix A will be 2000 by 2000

  Number of floating point operations = -1179869184
  Estimated CPU time is -0.453796 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK          75.206447      -15.688405
  IKJ         171.293599       -6.887993
  JIK         107.549093      -10.970517
  JKI          35.372366      -33.355676
  KIJ         175.893450       -6.707863
  KJI          36.211656      -32.582580

MXM:
  Normal end of execution.

Parallelized Local outcomes:

Matrix B is 100 by 100
  Matrix C is 100 by 100
  Matrix A will be 100 by 100

  Number of floating point operations = 2000000
  Estimated CPU time is 0.000769 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.020095       99.527246
  IKJ           0.000093    21505.376344
  JIK           0.000097    20618.556701
  JKI           0.000092    21739.130435
  KIJ           0.000093    21505.376344
  KJI           0.000096    20833.333333

MXM:
  Normal end of execution.

Matrix B is 200 by 200
  Matrix C is 200 by 200
  Matrix A will be 200 by 200

  Number of floating point operations = 16000000
  Estimated CPU time is 0.006154 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.006754     2368.966538
  IKJ           0.000094   170212.765957
  JIK           0.000097   164948.453608
  JKI           0.000093   172043.010753
  KIJ           0.000092   173913.043478
  KJI           0.000078   205128.205128

MXM:
  Normal end of execution.

Matrix B is 500 by 500
  Matrix C is 500 by 500
  Matrix A will be 500 by 500

  Number of floating point operations = 250000000
  Estimated CPU time is 0.096154 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.018673    13388.314679
  IKJ           0.000072  3472222.222222
  JIK           0.000071  3521126.760564
  JKI           0.000074  3378378.378378
  KIJ           0.000071  3521126.760563
  KJI           0.000074  3378378.378378

MXM:
  Normal end of execution.

Matrix B is 1000 by 1000
  Matrix C is 1000 by 1000
  Matrix A will be 1000 by 1000

  Number of floating point operations = 2000000000
  Estimated CPU time is 0.769231 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.000839  2383790.226460
  IKJ           0.000100  19999999.999999
  JIK           0.000102  19607843.137254
  JKI           0.000103  19417475.728154
  KIJ           0.000107  18691588.785047
  KJI           0.000104  19230769.230771

MXM:
  Normal end of execution.

Matrix B is 2000 by 2000
  Matrix C is 2000 by 2000
  Matrix A will be 2000 by 2000

  Number of floating point operations = -1179869184
  Estimated CPU time is -0.453796 seconds.

  The number of processors available = 8
  The number of threads available    = 8

  Method     Cpu Seconds       MegaFlopS
  ------  --------------  --------------
  IJK           0.007699  -153249.666710
  IKJ           0.000107  -11026814.803739
  JIK           0.000115  -10259732.034782
  JKI           0.000116  -10171286.068965
  KIJ           0.000285  -4139891.873684
  KJI           0.000119  -9914867.092439

MXM:
  Normal end of execution.

GUANE1 Execution's steps:

Firstly we gotta launch our BATCH script as follow:

sbatch script.sh   
