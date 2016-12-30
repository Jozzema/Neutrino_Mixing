#include <iostream>
#include <string.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_vector.h>

#include "neutrino.hpp"

using namespace std;


// método probabilidad_oscilacion
//   multiplicamos a nuestro prod_escalar una fase compleja que depende
//   de energia, distancia y diferencia de masas
//   este paso sirve para incluir aproximaciones relativistas en el algoritmo
// devolvemos un real entre 0 y 1 --> probabilidad de oscilacion
double neutrino::probabilidad_oscilacion() {
  return 0L;
}

// método debug
//    efectos de depuración
// devuelve un string representación del Neutrino
string neutrino::debug () {
  return "Neutrino";
}

/*
  void dim(gsl_vector_complex* v,int j) {
    v=gsl_vector_complex_alloc(j);
  }

  double probabilidad_oscilacion() {
    int i;
    gsl_complex probabilidad, prod_escalar,fase_E_L,aux,aux2;
    double E,L,resultado;
    double deltam[3];
    gsl_vector_complex* nu1_estrella; //almacenamos el complejo conjugado de nu1 aqui

    //complejo conjugado de nu1*

    for (i=0;i<=(nu1->size);i++) {
      aux=gsl_complex_conjugate(gsl_vector_complex_get(nu1,i));
      gsl_vector_complex_set(nu1_estrella,i,aux);
    }

    //gsl nos permite definir un complejo en forma polar
    fase_E_L=gsl_complex_polar (1,deltam[i]*L/(4*E));

    //construimos un producto escalar usando funciones definidas en gsl
    //para sumar y multiplicar variable compleja --> el resultado ha de ser
    //un gsl_complex

    gsl_vector_complex_mul(nu1_estrella,nu2);
    GSL_SET_COMPLEX(&prod_escalar,0,0);
    for (i=0;i<=(nu2->size);i++) {
      aux2=gsl_vector_complex_get(nu1_estrella,i);
      prod_escalar=gsl_complex_add(aux2,prod_escalar);
    }

    //multiplicamos a nuestro prod_escalar una fase compleja que depende
    //de energia, distancia y diferencia de masas
    //este paso sirve para incluir aproximaciones relativistas en el algoritmo
    probabilidad=gsl_complex_mul(prod_escalar,fase_E_L);

    resultado=gsl_complex_abs2(probabilidad);

    //devolvemos un real entre 0 y 1 --> probabilidad de oscilacion
    return resultado;
  }
};
*/
