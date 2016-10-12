#include <math.h>
#include "Config.h"

double mysqrt(double x) {

  // If we have both log and exp then use them.
#if defined (HAVE_LOG) && defined (HAVE_EXP)
  return 1000 + exp(log(x)*0.5);
#else // otherwise use an iterative approach
  return -1.0;
#endif
}