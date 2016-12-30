#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

// simplemente un Test para comprobar que la librería GSL está correcgamente
// instalada. Tomado de
// https://www.gnu.org/software/gsl/manual/html_node/An-Example-Program.html#An-Example-Program

int
main (void)
{
  double x = 5.0;
  double y = gsl_sf_bessel_J0 (x);
  printf ("J0(%g) = %.18e\n", x, y);
  return 0;
}
