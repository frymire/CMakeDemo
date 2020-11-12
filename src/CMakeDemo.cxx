
#include <cstdio>
#include <cmath>
#include <string>

// Get the value of the CMake USE_MYMATH variable.
#include "Config.h"

// Include the custom math library, if indicated by USE_MYMATH.
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

// Prints the square root of a number.
int main(int argc, char *argv[]) {

  printf("%s Version %d.%d\n", argv[0], CMakeDemo_VERSION_MAJOR, CMakeDemo_VERSION_MINOR);

  if (argc != 2) {
    printf("Usage: %s number\n", argv[0]);
    return 1;
  }

  //double inputValue = atof(argv[1]); // from C standard library math.h
  const double inputValue = std::stod(argv[1]); // requires c++11

#ifdef USE_MYMATH
  printf("Using custom math library.\n");
  double outputValue = funnySqrt(inputValue);
#else
  printf("Using sqrt() from cmath.\n");
  double outputValue = sqrt(inputValue);
#endif

  fprintf(stdout, "The square root of %g is %g.\n", inputValue, outputValue);
  return 0;
}
