
#include "MathFunctions.h"

#include <stdio.h>
#include <math.h>

#include "Config.h" // get HAVE_LOG and HAVE_EXP
#include "Table.h" // get the generated sqrtTable

double logSqrt(double x) {
    printf("Using exp(log(x)) * 0.5.\n");
    return exp(log(x)*0.5);
}

double iterativeSqrt(double x) {

  printf("Using iterative method...\n");

  // Initialize result, using the lookup table, if appropriate.
  double result = x;
  if (x >= 1 && x < 100) result = sqrtTable[static_cast<int>(x)];
  printf("Initialized result to %g.\n", result);

  double delta;

  // Find the result iteratively.
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) result = 0.1;
    delta = x - (result * result);
    result = result + 0.5 * delta / result;
    printf("sqrt(%g) = %g\n", x, result);
  }

  return result;
}

double funnySqrt(double x) {

  if (x <= 0) return 0;

// Use CMake variables passed in through Config.h to determine which
// function to call. Of course, HAVE_LOG and HAVE_EXP will almost always
// be true, so iterativeSqrt probably won't ever be called.
#if defined (HAVE_LOG) && defined (HAVE_EXP)
//  return logSqrt(x);
//#else
  return iterativeSqrt(x);
#endif

}
