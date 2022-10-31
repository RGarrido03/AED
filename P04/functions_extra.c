//
// Tomás Oliveira e Silva, AED, October 2021
//
// the functions for the extra exercises of class P.04
//

typedef signed long long s64;
#include <stdio.h>

// Elapsed time function definition (Linux and macOS) --------------------

#if defined(__linux__) || defined(__APPLE__)

#include <time.h>

double cpu_time(void)
{
  struct timespec current_time;

  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&current_time) != 0)  // the first argument could also be CLOCK_REALTIME
    return -1.0; // clock_gettime() failed!!!
  return (double)current_time.tv_sec + 1.0e-9 * (double)current_time.tv_nsec;
}

#endif

// Functions -------------------------------------------------------------

int g1(int n)
{
  int i,j,r = 0;

  for(i = 0;i <= n;i++)
    for(j = i;j >= 0;j--)
      r += i - j;
  return r;
}

int g2(int n)
{
  int r = 0;

  for(int i = 0;i < 2 * n;i += 2)
    for(int j = i;j <= 2 * n;j += 2)
      r += j;
  return r;
}

void g3(int n,int *a)
{
  for(int i = 1;i <= n;i++)
    for(int j = i;j <= n;j += i)
      a[j] = i;
}

int g4(int n)
{
  int r = 0;

  for(int i = 1;i <= n;i *= 2)
    r += i;
  return r;
}

int main(void)
{
  double dt1 = 0.0,dt2 = 0.0,dt3 = 0.0,dt4 = 0.0;
  s64 n;
  int a[1000000];

  // printf("  n v                    f      time\n");
  for (int p=1; p<15; p++)
  {
    n = 1 << p;
    if(n < (s64)40 || dt1 < 10.0) { dt1 = cpu_time(); g1(n); dt1 = cpu_time() - dt1; printf("%5d 1 %9.6f\n",(int)n,dt1); }
    if(n < (s64)40 || dt2 < 10.0) { dt2 = cpu_time(); g2(n); dt2 = cpu_time() - dt2; printf("%5d 2 %9.6f\n",(int)n,dt2); }
    if(n < (s64)40 || dt3 < 10.0) { dt3 = cpu_time(); g3(n,a); dt3 = cpu_time() - dt3; printf("%5d 3 %9.6f\n",(int)n,dt3); }
    if(n < (s64)40 || dt4 < 10.0) { dt4 = cpu_time(); g4(n); dt4 = cpu_time() - dt4; printf("%5d 4 %9.6f\n",(int)n,dt4); }
  }
  return 0;
}
