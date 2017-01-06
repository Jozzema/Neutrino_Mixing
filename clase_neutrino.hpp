//clase neutrino

/*
  en esta clase recogemos los atributos necesarios para
  definir un neutrino. Algunas condiciones quedaran fuera
  de la clase para que la funcion prob_oscilacion sea mas facil de
  escribir e implementar
*/

#include <string.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_vector.h>
#include <cmath>
#include <iostream>

using namespace std;

class neutrino {
private:
  string flavor; //e,mu,tau -> depende del sabor "estado" sera diferente
  gsl_vector*theta=gsl_vector_alloc(3); //alojamos los angulos de mezcla
  gsl_complex faseCP; //fase de Dirac (=0 en un principio)
  gsl_vector*deltamsquare=gsl_vector_alloc(3); //diferencias de masa
  gsl_vector_complex*estado=gsl_vector_complex_alloc(3); //U*|v_i> --> prob

public:
  neutrino(string sabor){flavor=sabor;}
  ~neutrino(); //constructor y destructor de clase
  
  void set_flavor(string sabor) {flavor=sabor;}
  string get_flavor() {return flavor;} //control sobre flavor

  //control sobre los angulos de mezcla
  void set_theta(int i, double angulo) {
    angulo=angulo*acos(-1)/180;
    gsl_vector_set(theta,i,angulo);
      }
  double get_theta(int i) { return gsl_vector_get(theta,i);}

  //control sobre faseCP
  void set_faseCP(double dirac) {
    dirac=dirac*acos(-1)/180;
    faseCP=gsl_complex_polar(1,dirac);
  }

  double get_faseCP_real() { return GSL_REAL(faseCP);}
  double get_faseCP_imag() { return GSL_IMAG(faseCP);}

  //control sobre diferencias de masas
  void set_deltamsquare(int i, double deltam) {
    gsl_vector_set(deltamsquare,i,deltam);
  }

  double get_deltamsquare(int i) { return gsl_vector_get(deltamsquare,i);}

  //control sobre el estado inicial
  void set_estado(string flavor) {
    string e="e";
    string mu="mu";
    string tau="tau";
    double aux,aux3;
    gsl_complex aux2,aux4;

    //por ahora no necesitamos la matriz U, podemos escribir los
    //estados uno a uno
    
    //controlamos el estado inicial con un condicional

    if (flavor==e) {
      
      gsl_vector_complex_set(estado,1,gsl_complex_rect(cos(this->get_theta(1))*sin(this->get_theta(3)),0));
      
      gsl_vector_complex_set(estado,2,gsl_complex_rect(sin(this->get_theta(1))*cos(this->get_theta(3)),0));
      
      gsl_vector_complex_set(estado,3,gsl_complex_mul_real(gsl_complex_conjugate(faseCP),sin(this->get_theta(3))));
      
    } else if (flavor==mu) {
      
      aux=-sin(this->get_theta(1))*cos(this->get_theta(2));
      aux2=gsl_complex_mul_real(faseCP,-cos(this->get_theta(1))*sin(this->get_theta(2))*sin(this->get_theta(3)));
      
      gsl_vector_complex_set(estado,1,gsl_complex_add_real(aux2,aux));
      
      aux3=cos(this->get_theta(1))*cos(this->get_theta(2));
      aux4=gsl_complex_mul_real(faseCP,-sin(this->get_theta(1))*sin(this->get_theta(2))*sin(this->get_theta(3)));
      
      gsl_vector_complex_set(estado,2,gsl_complex_add_real(aux4,aux3));
      
      gsl_vector_complex_set(estado,3,gsl_complex_rect(sin(this->get_theta(2))*cos(this->get_theta(3)),0));
      
    } else if (flavor==tau) {

      aux=sin(this->get_theta(1))*sin(this->get_theta(2));
      aux2=gsl_complex_mul_real(faseCP,-cos(this->get_theta(1))*cos(this->get_theta(2))*sin(this->get_theta(3)));

      gsl_vector_complex_set(estado,1,gsl_complex_add_real(aux2,aux));

      aux3=-cos(this->get_theta(1))*sin(this->get_theta(2));
      aux4=gsl_complex_mul_real(faseCP,-sin(this->get_theta(1))*cos(this->get_theta(2))*sin(this->get_theta(3)));

      gsl_vector_complex_set(estado,2,gsl_complex_add_real(aux4,aux3));

      gsl_vector_complex_set(estado,3,gsl_complex_rect(cos(this->get_theta(2))*cos(this->get_theta(3)),0));

    } else {

      cout << "Debes escribir e,mu o tau.\n";
    }
    //cerramos el metodo "estado"

  }

  //getters de "estado"

  gsl_complex get_estado(int j) {
    return gsl_vector_complex_get(estado,j);
  }

  /*
    la mayoria de getters y setters son llamadas a
    metodos de gsl, pero sirven para usar nuestra nomenclatura
  */

  /*
    aunque cada vez que construyamos un objeto neutrino
    tengamos que llamar al setter de angulos y masas,
    nos sirve para controlar mejor el estado del neutrino
    de forma interna, i. e., desde dentro de la clase
  */

  //cerramos la clase

};
    
		      
       
  

  
  
  
