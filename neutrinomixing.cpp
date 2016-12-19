//Programa que pide por pantalla energia(GeV), distancia(km)
// y devuelve en un fichero la probabilidad de mezcla o supervivencia de
// un autoestado debil del neutrino

#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

int main () {

  ifstream ficherolectura;
  ofstream ficherosalida;
  double deltam[3], theta[3];
  double E, L, n_iteraciones;
  char neutrino_inicial, neutrino_final;
  int i;
  
  //leemos diferencias de masas y angulos de mezcla
  //desde un fichero, asi seran mas faciles de modificar
    ficherolectura.open("datos.txt");
  
    while(!ficherolectura.eof()) //compruebo antes de empezar a leer
      {
	ficherolectura >> deltam[0] >> deltam[1] >> deltam[2] >> endl;
	ficherolectura >> theta[0] >> theta[1] >> theta[2];
      }
    ficherolectura.close();
    //muestro los archivos por pantalla para comprobar
    //que se han leido bien
    cout << "valores de diferencias de masas:" << endl;
    cout << "aqui mostramos un vector que recoge las diferencias" << endl;
    cout << "de masas para los autoestados de masa del neutrino," << endl;
    cout << "el primer elemento se corresponde con deltam12," << endl;
    cout << "el segundo elemento se corresponde con deltam13 " << endl;												          cout << "y el tercer elemento se corresponde con deltam23:" << endl;


    i=0;
    for (i=0;i<=2;i++) {
      cout << "deltam" << i << ": " << deltam[i] << endl;
    }

    cout << endl;
    cout << endl;
    cout << "Hacemos lo mismo para los angulos de mezcla:" << endl;
    i=0; //vuelvo a iniciar el contador a cero

    for (i=0;i<=2;i++) {
      cout << "theta" << i << ": " << theta[i] << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Introduzca un valor para la energia (GeV):" << endl;
    cin >> E; //Pido un valor para la energia

    cout << "Introduzca un valor para la distancia (km):" << endl;
    cin << L; //Pido un valor para la distancia,
    // que me servira para discretizar equiespaciadamente
    // los resultados que obtenga y escribirlos en un fichero

    cout << "Introduzca el numero de iteraciones que desea:" << endl;
    cin << n_iteraciones; //me da el numero de divisiones de longitud

    

    

    
    
  
  
