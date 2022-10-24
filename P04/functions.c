//
// Tomás Oliveira e Silva, AED, October 2021
//
// the functions for the first exercise of class P.04
// (for a given positive value of n, find a formula for the return value of each function)
//

typedef signed long long s64;
#include <stdio.h>

// -----------------------------------------------------------------------
// Elapsed time function definition, according to the OS

#if defined(__linux__) || defined(__APPLE__) // GNU/Linux and macOS

#include <time.h>

double cpu_time(void)
{
  struct timespec current_time;

  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&current_time) != 0)  // the first argument could also be CLOCK_REALTIME
    return -1.0; // clock_gettime() failed!!!
  return (double)current_time.tv_sec + 1.0e-9 * (double)current_time.tv_nsec;
}

#endif


#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64) // Windows

#include <windows.h>

double cpu_time(void)
{
  static LARGE_INTEGER frequency;
  static int first_time = 1;
  LARGE_INTEGER current_time;

  if(first_time != 0)
  {
    QueryPerformanceFrequency(&frequency);
    first_time = 0;
  }
  QueryPerformanceCounter(&current_time);
  return (double)current_time.QuadPart / (double)frequency.QuadPart;
}

#endif

// -----------------------------------------------------------------------
// Functions

int f1(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += 1;
  return r;
}
// big_theta(n)

int f2(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += 1;
  return r;
}
// big_theta(n²)

int f3(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= n;j++)
      r += 1;
  return r;
}
// big_theta(n²)

int f4(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += i;
  return r;
}
// big_theta(n)

int f5(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = i;j <= n;j++)
      r += 1;
  return r;
}
// big_theta(n²)

int f6(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += j;
  return r;
}
// big_theta(n²)

// ------------------------------------------------------------------------
// Measure time of function execution
int main(void)
{
  double dt1 = 0.0,dt2 = 0.0,dt3 = 0.0,dt4 = 0.0,dt5 = 0.0,dt6 = 0.0;
  s64 n,f;

  // printf("  n v                    f      time\n");
  for (int p=1; p<15; p++)
  {
    n = 1 << p;
    if(n < (s64)40 || dt1 < 10.0) { dt1 = cpu_time(); f = f1(n); dt1 = cpu_time() - dt1; printf("%5d 1 %20lld %9.6f\n",(int)n,f,dt1); }
    if(n < (s64)40 || dt2 < 10.0) { dt2 = cpu_time(); f = f2(n); dt2 = cpu_time() - dt2; printf("%5d 2 %20lld %9.6f\n",(int)n,f,dt2); }
    if(n < (s64)40 || dt3 < 10.0) { dt3 = cpu_time(); f = f3(n); dt3 = cpu_time() - dt3; printf("%5d 3 %20lld %9.6f\n",(int)n,f,dt3); }
    if(n < (s64)40 || dt4 < 10.0) { dt4 = cpu_time(); f = f4(n); dt4 = cpu_time() - dt4; printf("%5d 4 %20lld %9.6f\n",(int)n,f,dt4); }
    if(n < (s64)40 || dt5 < 10.0) { dt5 = cpu_time(); f = f5(n); dt5 = cpu_time() - dt5; printf("%5d 5 %20lld %9.6f\n",(int)n,f,dt5); }
    if(n < (s64)40 || dt6 < 10.0) { dt6 = cpu_time(); f = f6(n); dt6 = cpu_time() - dt6; printf("%5d 6 %20lld %9.6f\n",(int)n,f,dt6); }
  }
  return 0;
}
