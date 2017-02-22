/*
    main de neutrino_mixing. Pedimos por pantalla el input
    y mostramos (por ahora) output tambien por pantalla.
    necesitamos nu_functions.h y clase_neutrino.hpp
*/

#include <iostream>
#include <string.h>
#include <fstream>

#include "nu_functions.h"

//#include "clase_neutrino.hpp"

using namespace std;

int main () {



//definimos variables que necesitamos
    int N; //precision
    double E1,E2; //intervalo de energia
    double EE;
    string sabor_i, sabor_f;
    int k; //modo neutrino/antineutrino
    double L; //baseline

//primero pedimos modo
    cout << "modo neutrino(1) o antineutrino(2):" << endl;
    cin >> k;

//pedimos los sabores de los neutrinos
    cout << "sabores: e, mu y tau." << endl;
    cout << "sabor del neutrino inicial: " << endl;
    cin >> sabor_i;

    cout << "sabor del neutrino final: " << endl;
    cin >> sabor_f;

    cout << "Intervalo de energias: " << endl;
    cout << "Energia inicial E1: " << endl;
    cin >> E1;

    cout << "Energia final E2: " << endl;
    cin >> E2;

    cout << "Longitud :" << endl;
    cin >> L;

    cout << "Precision: " << endl;
    cin >> N;

    

//creamos nuestros neutrinos
    neutrino nu_i(sabor_i);
    neutrino nu_f(sabor_f);


//damos entrada a theta y deltam

    nu_i.set_deltamsquare(0,7.5e-5);
    nu_i.set_deltamsquare(1,2.457e-3);
    nu_i.set_deltamsquare(2,2.457e-3);

    nu_f.set_deltamsquare(0,7.5e-5);
    nu_f.set_deltamsquare(1,2.457e-3);
    nu_f.set_deltamsquare(2,2.457e-3);

    nu_i.set_theta(0,33.48);
    nu_i.set_theta(1,42.3);
    nu_i.set_theta(2,8.5);

    nu_f.set_theta(0,33.48);
    nu_f.set_theta(1,42.3);
    nu_f.set_theta(2,8.5);

//damos entrada a la fase de Dirac
    nu_i.set_faseCP(0); //en principio la hacemos cero 
    nu_f.set_faseCP(0);

//iniciamos los estados de los neutrinos
    nu_i.set_estado(sabor_i);
    nu_f.set_estado(sabor_f);


    //vamos a mostrar los estados por  pantalla

    cout << "Neutrino inicial: " << endl;
    cout << "("<< GSL_REAL(nu_i.get_estado(0)) << "+" << GSL_IMAG(nu_i.get_estado(0)) << ")" << "|nu_1> + " << "("<< GSL_REAL(nu_i.get_estado(1)) << "+" << GSL_IMAG(nu_i.get_estado(1)) << ")" <<
      "|nu_2> + " << "("<< GSL_REAL(nu_i.get_estado(2)) << "+" << GSL_IMAG(nu_i.get_estado(2)) << ")" << "|nu_3>" << endl;

    cout << "Neutrino final: " << endl;
    cout << "("<< GSL_REAL(nu_f.get_estado(0)) << "+" << GSL_IMAG(nu_f.get_estado(0)) << ")" << "|nu_1> + " << "("<< GSL_REAL(nu_f.get_estado(1)) << "+" << GSL_IMAG(nu_f.get_estado(1)) << ")" <<
      "|nu_2> + " << "("<< GSL_REAL(nu_f.get_estado(2)) << "+" << GSL_IMAG(nu_f.get_estado(2)) << ")" << "|nu_3>" << endl;

//Damos los resultados por pantalla
//IMPORTANTE: sacarlos por fichero mas adelante
/*
cout << "A continuacion mostraremos los resultados por pantalla: " << endl;
 cout << "PASO PROB_OSC ENERGIA(GeV)" << endl;

EE=E1;

 for (int i=0;i<=N;i++){
   cout << i+1 << " " << prob_osc(k,nu_i,nu_f,EE,L) << " " << EE << endl;
    EE=EE+((E2-E1)/N); 
}
*/

    cout <<"Mostramos los datos en el fichero datos.txt" << endl;

    ofstream fichero("datos.txt");

    EE=E1;

    for (int i=0;i<=N;i++){
   fichero << i+1 << " " << prob_osc(k,nu_i,nu_f,EE,L) << " " << EE << endl;
    EE=EE+((E2-E1)/N); 
}

    fichero.close();

    cout << "simulacion terminada" << endl;
    
    
 

    return 0;
}
