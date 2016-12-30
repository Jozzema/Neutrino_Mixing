# Test de instalación de la librerias GSL
test_gsl : test_gsl.c
		gcc -Wall -I/usr/local/include -c test_gsl.c
		gcc -L/usr/local/lib test_gsl.o -o test_gsl -lgsl -lgslcblas -lm

test_neutrino: test_neutrino.cpp neutrino.hpp neutrino.cpp
		g++ -Wall -Wextra test_neutrino.cpp neutrino.cpp -o test_neutrino 
