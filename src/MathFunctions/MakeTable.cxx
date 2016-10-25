#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Writes a table of pre-computed square root values to a
// file specified as a command line argument.
int main(int argc, char *argv[]) {

  // Create the output file.
  if (argc != 2) return 1;
  FILE *fout = fopen(argv[1], "w");
  if (!fout) return 1;

  // Populate the file with a table of square roots.
  fprintf(fout, "double sqrtTable[] = {\n");
  for (int i = 0; i < 100; ++i) {
    fprintf(fout, "%g,\n", sqrt(static_cast<double>(i)));
  }

  // Close the table with a zero.
  fprintf(fout, "0};\n");
  fclose(fout);

  return 0;
}
