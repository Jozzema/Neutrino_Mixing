/* funciones:
prob_osc -> probabilidad de oscilacion de nu_i a nu_f para baseline
y energia fijos (1 neutrino, 2 antineutrino)

pantalla -> muestra por pantalla los resultados para E, E+deltaE con
N pasos

file -> igual que "pantalla" pero recoge el output en un archivo.
*/

#include <iostream>
#include <string.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_vector.h>
#include <cmath>

#include "clase_neutrino.hpp"


double prob_osc(int k,neutrino nu_i,neutrino nu_f, double E, double L);
double getReal(neutrino nu_i,neutrino nu_f,int i,int j);
double getImag(neutrino nu_i,neutrino nu_f,int i,int j);



double prob_osc(int k,neutrino nu_i,neutrino nu_f, double E, double L) {

  double resultado;  

  /*dividimos el proceso en modo neutrino/modo antineutrino
   */

//calculamos los sumandos de la expresion final para despues jugar con ellos
//en modo neutrino o antineutrino, supervivencia u oscilacion

  double real=(getReal(nu_i,nu_f,0,1)*pow(sin((nu_i.get_deltamsquare(0)*L*1.27)/E),2))+
         (getReal(nu_i,nu_f,1,2)*pow(sin((nu_i.get_deltamsquare(1)*L*1.27)/E),2))+
         (getReal(nu_i,nu_f,0,2)*pow(sin((nu_i.get_deltamsquare(2)*L*1.27)/E),2));

  double imag=(getImag(nu_i,nu_f,0,1)*sin((nu_i.get_deltamsquare(0)*L*2.54)/E))+
         (getImag(nu_i,nu_f,1,2)*sin((nu_i.get_deltamsquare(1)*L*2.54)/E))+
         (getImag(nu_i,nu_f,0,2)*sin((nu_i.get_deltamsquare(2)*L*2.54)/E));           

//modo neutrino 
   if (k==1) {

     if (nu_i.get_flavor()==nu_f.get_flavor()) {

       return resultado=1-(4*real)+imag; 
     } 

     else {return resultado=-(4*real)+imag;}
   }
    else if (k==2) {
      if (nu_i.get_flavor()==nu_f.get_flavor()) {

	return resultado=1-(4*real)-imag; 
     } 

      else {return resultado=-(4*real)-imag;}
    } else {
      std::cout << "No has seleccionado modo adecuadamente";
      return 0;
}
}


/*necesitamos funciones para obtener las partes reales 
e imaginarias de la prob de oscilacion. GSL puede hacerlo
pero por separado es mas facil de controlar. Ademas
incorporamos nuestra nomenclatura
*/

double getReal(neutrino nu_i,neutrino nu_f, int i, int j) {
  gsl_complex aux1;
  gsl_complex aux2;
  gsl_complex aux3;
  gsl_complex aux4;
  gsl_complex resultado;

//calculo U_ii*U_ijU_fiU_fj*

  aux1=gsl_complex_conjugate (nu_i.get_estado(i));
  aux2=gsl_complex_conjugate (nu_f.get_estado(j));

  aux3=gsl_complex_mul(aux1,nu_i.get_estado(j));
  aux4=gsl_complex_mul(aux2,nu_f.get_estado(i));

  resultado=gsl_complex_mul(aux3,aux4);

//ahora retornamos la parte real del resultado  

  return GSL_REAL(resultado);
}

//misma funcion pero para parte imaginaria

double getImag(neutrino nu_i,neutrino nu_f, int i, int j) {
  gsl_complex aux1;
  gsl_complex aux2;
  gsl_complex aux3;
  gsl_complex aux4;
  gsl_complex resultado;

//calculo U_ii*U_ijU_fiU_fj*

  aux1=gsl_complex_conjugate (nu_i.get_estado(i));
  aux2=gsl_complex_conjugate (nu_f.get_estado(j));

  aux3=gsl_complex_mul(aux1,nu_i.get_estado(j));
  aux4=gsl_complex_mul(aux2,nu_f.get_estado(i));

  resultado=gsl_complex_mul(aux3,aux4);

//ahora retornamos la parte real del resultado  

  return GSL_IMAG(resultado);
}



