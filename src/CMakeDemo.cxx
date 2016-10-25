#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Get the value of the CMake USE_MYMATH variable.
#include "Config.h"

// Include the custom math library, if indicated by USE_MYMATH.
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

// Prints the square root of a number.
int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
    printf("Usage: %s number\n", argv[0]);
    return 1;
  }

  double inputValue = atof(argv[1]);

#ifdef USE_MYMATH
  printf("Using custom math library.\n");
  double outputValue = funnySqrt(inputValue);
#else
  printf("Using sqrt() from math.h.\n");
  double outputValue = sqrt(inputValue);
#endif

  fprintf(stdout, "The square root of %g is %g.\n", inputValue, outputValue);
  return 0;
}
