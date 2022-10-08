//
// Tomás Oliveira e Silva, AED, October 2022
//
// Program to factor integers larger than 1
//

#include <stdio.h>
#include <stdlib.h>

int factor(int n,int *prime_factors,int *multiplicity)
{
  long d; // long is needed, because int causes an arithmetic overflow
  int n_factors;

  n_factors = 0;

  /*
  try the factors d = 2,3,5,7,9,...
    these include all the primes, as well as many odd composite numbers
    these last are harmless, but slow the program down
    getting rid of them would, however, require much more complicated code
    the expression (d+1)|1 has the effect of adding 1 to d if d is even and adding 2 if it is odd
      note that the expression (x|1) is the bitwise or of the bits of x with the bits of the constant 1,
      so in this case it makes the least significant bit of the result always 1 (odd integer!)
  
      d  d+1  (d+1)|1
     --  ---  -------
      2    3        3
      3    4        5
      4    5        5
      5    6        7
  */
  
  for(d = 2;d * d <= n;d = (d + 1) | 1)
  {
    if(n % d == 0)
    {
      prime_factors[n_factors] = d; // d is a prime factor
      multiplicity[n_factors] = 0;
      do
      {
        n /= d;
        multiplicity[n_factors]++;
      }
      while(n % d == 0);
      n_factors++;
    }
  }

  if(n > 1)
  {
    // the remaining divisor, if any, must be a prime number
    prime_factors[n_factors] = n;
    multiplicity[n_factors++] = 1;
  }

  return n_factors;
}


// Calculating the number of divisors of n
// There are (1+m[0])*(1+m[1])*...*(1+m[nf-1]) divisors.
int calculate_divisor_number(int num_factors, int *multiplicity)
{
  int a;
  int divisors_number = (1 + multiplicity[0]); // Set the first
  for(a = 1; a <= (num_factors-1); a++)
  {
    divisors_number *= (1 + multiplicity[a]);
  }
  return divisors_number;
}


// Calculate divisors
int calculate_divisors(int n, int divisors_number, int num_factors, int *factors, int *multiplicity, int *divisors)
{
  int a,j,k;
  divisors[0] = 1; // The first divisor is always 1
  divisors[divisors_number - 1] = n; // The last divisor is always the number itself

  k = 1; // divisor number counter
  for (j = 0; j < num_factors; j++) // j is a factorial number counter
  {
    if (multiplicity[j] == 1)
    {
      divisors[k] = factors[j];
      /*
      -1-k counts backwards.
      The prime factor always has a matching divisor (e.g. 30/2=15 -> both 2 and 15 are divisors).
      */
      divisors[divisors_number - 1 - k] = n / factors[j];
      k++;
    }
    else
    {
      a = 1;
      while (a <= multiplicity[j])
      {
        divisors[k] = factors[j] * a;
        divisors[divisors_number - 1 - k] = n / factors[j] * a;
        a++;
        k++;
      }
    }
  }
  return 0;
}


int main(int argc,char **argv)
{
  int i,j,loop,n,nf,f[16],m[16]; // the product of the first 16 primes is larger than 2^64
  
  for(i = 1;i < argc;i++)
  {
    if((n = atoi(argv[i])) > 1)
    {
      // Calculate the prime factors
      nf = factor(n,f,m);

      // Print the output
      printf("%d = ",n);
      for(j = 0;j < nf;j++)
        if(m[j] == 1)
          printf("%s%d",(j == 0) ? "" : "*",f[j]);
        else
          printf("%s%d^%d",(j == 0) ? "" : "*",f[j],m[j]);
      printf(" (%s)\n",(nf == 1 && m[0] == 1) ? "prime" : "composite");
      
      // Calculate the number of divisors
      int divisors_number = calculate_divisor_number(nf,m); // Check function above

      // Calculate the number divisors and then print them
      int divisors[divisors_number];
      calculate_divisors(n,divisors_number,nf,f,m,divisors); // Check function above
      printf("Number divisors: ");
      for (loop = 0; loop < divisors_number; loop++)
      {
        printf("%d ", divisors[loop]);
      }
      printf("\n");
    }
  }
  return 0;
}