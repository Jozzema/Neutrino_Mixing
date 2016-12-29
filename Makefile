# Test de instalación de la librerias GSL
test_gsl : test_gsl.c

		gcc -Wall -I/usr/local/include -c test_gsl.c
		gcc -L/usr/local/lib test_gsl.o -o test_gsl -lgsl -lgslcblas -lm
