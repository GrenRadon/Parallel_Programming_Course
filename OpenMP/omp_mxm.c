 #include <omp.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define CHUNKSIZE 700 //here we add a global variable 



//declaration of functions-----------------------------------------------------

int main ( int argc, char *argv[] );
int omp_get_num_threads(void);
double cpu_time ( );
double *matgen ( int m, int n, int *seed );
double mxm_ijk ( int n1, int n2, int n3, double b[], double c[] );
double mxm_ikj ( int n1, int n2, int n3, double b[], double c[] );
double mxm_jik ( int n1, int n2, int n3, double b[], double c[] );
double mxm_jki ( int n1, int n2, int n3, double b[], double c[] );
double mxm_kij ( int n1, int n2, int n3, double b[], double c[] );
double mxm_kji ( int n1, int n2, int n3, double b[], double c[] );
void timestamp ( );
//-----------------------------------------------------------------------------
/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for MXM.

  Discussion:

    MXV computes a matrix-matrix product in a number of ways, and reports
    the elapsed CPU time.

    The multiplication carried out is

      A(1:N1,1:N3) = B(1:N1,1:N2) * C(1:N2,1:N3)

    where B and C are real double precision matrices whose entries
    are assigned randomly.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    08 October 2010

  Author:

    John Burkardt

  Usage:

    mxm n1 n2 n3

  Parameters:

    Command line argument, int N1, N2, N3, defines the number of
    rows and columns in the two matrices.

  OpenMP Modification:

  27 Juin 2020 by Julián Eduardo Villamizar Peña,
  Universidad Industrial de Santander,
  julianeduardovillamizarpena_14021994@outlook.com,
  This OpenMP Modification makes a parallelization of
  the original Code taking into account some modifications
  proposed by a parallelization course available on.
*/
{
  double *b;
  double *c;
  double cpu_seconds;
  int flop_count;
  double mflops;
  int n1;
  int n2;
  int n3;
  int seed;
  double time_estimate;
  int thread_num;
  int h;

  timestamp ( );

  printf ( "\n" );
  printf ( "MXM:\n" );
  printf ( "  C version\n" );
  printf ( "  Compute matrix-matrix product A = B * C\n" );
/*
  Get N1.
*/
  if ( 1 < argc )
  {
    n1 = atoi ( argv[1] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter N1, the number of rows in B.\n" );
    scanf ( "%d", &n1 );
  }
/*
  Get N2.
*/
  if ( 2 < argc )
  {
    n2 = atoi ( argv[2] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter N2, the number of columns in B and rows in C.\n" );
    scanf ( "%d", &n2 );
  }
/*
  Get N3.
*/
  if ( 3 < argc )
  {
    n3 = atoi ( argv[3] );
  }
  else
  {
    printf ( "\n" );
    printf ( "  Enter N3, the number of columns in C.\n" );
    scanf ( "%d", &n3 );
  }
/*
  Record the amount of work.
  Each of the N1 * N3 entries of A requires N2 multiplies and N2 adds.
*/
  flop_count = 2 * n1 * n2 * n3;

  printf ( "\n" );
  printf ( "  Matrix B is %d by %d\n", n1, n2 );
  printf ( "  Matrix C is %d by %d\n", n2, n3 );
  printf ( "  Matrix A will be %d by %d\n", n1, n3 );
  printf ( "\n" );
  printf ( "  Number of floating point operations = %d\n", flop_count );
  time_estimate = ( double ) ( flop_count ) / 2.6E+09;
  printf ( "  Estimated CPU time is %f seconds.\n", time_estimate );

  thread_num = omp_get_max_threads ( );

  //this is a modification done for getting meta info about threads
  printf ( "\n" );
  printf ( "  The number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  The number of threads available    = %d\n", thread_num );
/*
  Set B and C.
*/
  seed = 1325;
  b = matgen ( n1, n2, &seed );
  c = matgen ( n2, n3, &seed );
  printf ( "\n" );
  printf ( "  Method     Cpu Seconds       MegaFlopS\n" );
  printf ( "  ------  --------------  --------------\n" );
/*
  IJK
*/
  cpu_seconds = mxm_ijk ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  IJK     %14f  %14f\n", cpu_seconds, mflops );
/*
  IKJ
*/
  cpu_seconds = mxm_ikj ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  IKJ     %14f  %14f\n", cpu_seconds, mflops );
/*
  JIK
*/
  cpu_seconds = mxm_jik ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  JIK     %14f  %14f\n", cpu_seconds, mflops );
/*
  JKI
*/
  cpu_seconds = mxm_jki ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  JKI     %14f  %14f\n", cpu_seconds, mflops );
/*
  KIJ
*/
  cpu_seconds = mxm_kij ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  KIJ     %14f  %14f\n", cpu_seconds, mflops );
/*
  KJI
*/
  cpu_seconds = mxm_kji ( n1, n2, n3, b, c );

  if ( 0.0 < cpu_seconds )
  {
    mflops = ( double ) ( flop_count ) / cpu_seconds / 1000000.0;
  }
  else
  {
    mflops = -1.0;
  }

  printf ( "  KJI     %14f  %14f\n", cpu_seconds, mflops );
/*
  Deallocate arrays.
*/
  free ( b );
  free ( c );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "MXM:\n" );
  printf ( "  Normal end of execution.\n" );

  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

double cpu_time ( void )

/******************************************************************************/
/*
  Purpose:

    CPU_TIME returns the current reading on the CPU clock.

  Discussion:

    The CPU time measurements available through this routine are often
    not very accurate.  In some cases, the accuracy is no better than
    a hundredth of a second.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 June 2005

  Author:

    John Burkardt

  Parameters:

    Output, double CPU_TIME, the current reading of the CPU clock, in seconds.

*/
{
  double value;

  value = ( double ) clock ( )
        / ( double ) CLOCKS_PER_SEC;

  return value;
}
/******************************************************************************/

double *matgen ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    MATGEN generates a random matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int M, N, the number of rows and columns
    of the matrix.

    Input, int *SEED, a seed for the random number
    generator.

    Output, double MATGEN[M*N], the matrix.
*/
{
  double *a;
  int i;
  int j;

  a = ( double * ) malloc ( m * n * sizeof ( double ) );
/*
  Set the matrix A.
*/
  for ( j = 0;j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      *seed = ( ( 3125 * *seed ) % 65536 );
      a[i+j*m] = ( *seed - 32768.0 ) / 16384.0;
    }
  }

  return a;
}
/******************************************************************************/

double mxm_ijk ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_IJK computes A = B * C using FOR I, FOR J, FOR K loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

  OpenMP Modification:
    02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
    e-mail:julianeduardovillamizarpena_1402994@outlook.com
    This OpenMP Modification makes a parallelization of the original Code by adding
    chunksize from a global variable, at the same time we add a pragma workflow
    which contain a region with a,b,c and chunk as shared variables among available
    threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
    taking into account we do not have to acess multiple times to memory for the Assignement
    of values inside the A Matrix.
*/
{

//Comments---------------------------------------------------------------------------

/* The way most languages store multi-dimensional arrays is by doing a conversion
like the following: If matrix has size, n by m [i.e. i goes from 0 to (n-1) and
j from 0 to (m-1) ], then: matrix[ i ][ j ] = array[ i*m + j ]. So its just like
a number system of base 'n'. Note that the size of the last dimension doesn't matter.
*/

/*Directly applying the mathematical definition of matrix multiplication gives
an algorithm that takes time on the order of n3 */

//------------------------------------------------------------------------------------

  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=700;
  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) ); //Assignement of memory
  //taking into account quantity of elements

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;

    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {

        for ( i = 0; i < n1; i++ )
        {
          for ( j = 0; j < n3; j++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( k = 0; k < n2; k++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
              /*printf("mira el resultado de A tras multiplicar: %f \n", a[i+j*n1]);*/
            }
          }
        }
    }

  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

double mxm_ikj ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_IKJ computes A = B * C using FOR I, FOR K, FOR J loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

    OpenMP Modification:
      02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
      e-mail:julianeduardovillamizarpena_1402994@outlook.com
      This OpenMP Modification makes a parallelization of the original Code by adding
      chunksize from a global variable, at the same time we add a pragma workflow
      which contain a region with a,b,c and chunk as shared variables among available
      threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
      taking into account we do not have to acess multiple times to memory for the Assignement
      of values inside the A Matrix.
*/
{
  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=CHUNKSIZE;

  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;
    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {
        for ( i = 0; i < n1; i++ )
        {
          for ( k = 0; k < n2; k++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( j = 0; j < n3; j++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
            }
          }
        }
      }
  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

double mxm_jik ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_JIK computes A = B * C using FOR J, FOR I, FOR K loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

    OpenMP Modification:
      02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
      e-mail:julianeduardovillamizarpena_1402994@outlook.com
      This OpenMP Modification makes a parallelization of the original Code by adding
      chunksize from a global variable, at the same time we add a pragma workflow
      which contain a region with a,b,c and chunk as shared variables among available
      threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
      taking into account we do not have to acess multiple times to memory for the Assignement
      of values inside the A Matrix.
*/
{
  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=CHUNKSIZE;

  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;
    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {
        for ( j = 0; j < n3; j++ )
        {
          for ( i = 0; i < n1; i++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( k = 0; k < n2; k++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
            }
          }
        }
      }

  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

double mxm_jki ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_JKI computes A = B * C using FOR J, FOR K, FOR I loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

    OpenMP Modification:
      02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
      e-mail:julianeduardovillamizarpena_1402994@outlook.com
      This OpenMP Modification makes a parallelization of the original Code by adding
      chunksize from a global variable, at the same time we add a pragma workflow
      which contain a region with a,b,c and chunk as shared variables among available
      threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
      taking into account we do not have to acess multiple times to memory for the Assignement
      of values inside the A Matrix.
*/
{
  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=CHUNKSIZE;

  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;
    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {
        for ( j = 0; j < n3; j++ )
        {
          for ( k = 0; k < n2; k++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( i = 0; i < n1; i++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
            }
          }
        }
      }

  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

double mxm_kij ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_KIJ computes A = B * C using FOR K, FOR I, FOR J loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

    OpenMP Modification:
      02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
      e-mail:julianeduardovillamizarpena_1402994@outlook.com
      This OpenMP Modification makes a parallelization of the original Code by adding
      chunksize from a global variable, at the same time we add a pragma workflow
      which contain a region with a,b,c and chunk as shared variables among available
      threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
      taking into account we do not have to acess multiple times to memory for the Assignement
      of values inside the A Matrix.
*/
{
  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=CHUNKSIZE;

  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;
    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {
        for ( k = 0; k < n2; k++ )
        {
          for ( i = 0; i < n1; i++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( j = 0; j < n3; j++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
            }
          }
        }
      }

  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

double mxm_kji ( int n1, int n2, int n3, double b[], double c[] )

/******************************************************************************/
/*
  Purpose:

    MXM_KJI computes A = B * C using FOR K, FOR J, FOR I loops.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    07 October 2010

  Author:

    John Burkardt

  Parameters:

    Input, int N1, N2, N3, define the orders of the
    matrices.

    Input, double B[N1*N2], C[N2*N3], the factor matrices.

    Output, double MXM_IJK, the elapsed CPU time.

    OpenMP Modification:
      02 Juib 2020 by Julián Eduardo Villamizar Peña, Universidad Industrial de Santander
      e-mail:julianeduardovillamizarpena_1402994@outlook.com
      This OpenMP Modification makes a parallelization of the original Code by adding
      chunksize from a global variable, at the same time we add a pragma workflow
      which contain a region with a,b,c and chunk as shared variables among available
      threads and i,j,k,n1,n2,n3 variables as private because are independant of every loops
      taking into account we do not have to acess multiple times to memory for the Assignement
      of values inside the A Matrix.
*/
{
  double *a;
  double cpu_seconds;
  int i,j,k;
  int chunk;
  chunk=CHUNKSIZE;

  a = ( double * ) malloc ( n1 * n3 * sizeof ( double ) );

  //Initialización of values of each element of A matrix.
  for ( j = 0; j < n3; j++ )
  {
    for ( i = 0; i < n1; i++ )
    {
      a[i+j*n1] = 0.0;
    }
  }

  cpu_seconds = cpu_time ( );

  #pragma omp parallel shared(a,b,c,chunk) private(i,j,k,n1,n2,n3)
     {
        for ( k = 0; k < n2; k++ )
        {
          for ( j = 0; j < n3; j++ )
          {
            #pragma omp for schedule(dynamic,chunk) ordered
            for ( i = 0; i < n1; i++ )
            {
              a[i+j*n1] = a[i+j*n1] + b[i+k*n1] * c[k+j*n2];
            }
          }
        }
      }

  cpu_seconds = cpu_time ( ) - cpu_seconds;

  free ( a );

  return cpu_seconds;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
