
#include <iostream>
#include <string.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_vector.h>

using namespace std;

// clase: neutrino
//
// Neutrino es una combinacion lineal de 3 (4 si añadimos neutrino esteril)
// autoestados de masa.
//
// Usamos libgsl para tratar numeros complejos y matrices

class neutrino {
private:
  // autoestados de masa del neutrino
  gsl_vector_complex* autoestado1, autoestado2, autoestado3;

public:
  neutrino() {};
  double probabilidad_oscilacion();
  string debug();

};
