//
// Tomás Oliveira e Silva, AED, October 2021
//
// program to print a table of the squares and square roots of some integers
//
// on GNU/Linux, run the command
//   man 3 printf
// to see the manual page of the printf function
//

#include <math.h>
#include <stdio.h>

void do_it(int N, char * filename)
{
  int i;
  FILE * f;

  f = fopen(filename, "w");

  fprintf(f, " n  n*n      sqrt(n)            sin(n)            cos(n)\n");
  fprintf(f, "-- ---- ----------------- ----------------- -----------------\n");
  
  for(i = 0;i <= N;i++){
    fprintf(f, "%2d %4d %17.15f %17.15f %17.15f\n",i,i * i,sqrt((double)i), sin((double)M_PI/180.0*i), cos((double)M_PI/180.0*i));
  }

  fclose(f);
}

int main(void)
{
  do_it(90, "table.txt");
  return 0;
}
