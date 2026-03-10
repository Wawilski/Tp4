
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//To compile: gcc montecarlo-pi.c -o montecarlo-pi
//Usage: ./montecarlo-pi

int main(int argc, char* argv[]) {
  double x,y,z;
  int count = 0;
  int seed = atoi(argv[1]);
  srand(seed);
  int n = (int) rand() % 50000 + 1; // Number of iterations

  for (int i = 0; i < n; i++) {
  x = (double) rand() / RAND_MAX;
  y = (double) rand() / RAND_MAX;
  z = x * x + y * y;
  if (z <= 1) count++;
  }

  printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);

  time_t stopped = time(0);

  return(0);
}
