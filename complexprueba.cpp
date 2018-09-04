#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;


int main() {
  numcomplex z1, z2;

  z1.a=1;
  z1.b=2;

  z2.a=3;
  z2.b=4;

/*
  cout<<"Raices n-esimas(z1, 3):";
  numcomplex_array z_raices;
  z_raices = raices_nesimas(z1, 3);
  for( k=0; k < 2; k++)
  cout << "\n("<<z_raices.array[k].a<<","<<z_raices.array[k].b<<")" << '\n';


    numcomplex polinomio=cplx_ev_poli(grado, coeficientes, z1);

    cout << "El polinomio evaluado en 1+2i es: ";
    cout << "("<<polinomio.a<<","<<polinomio.b<<")" << '\n';

    polinomio=cplx_horner(grado, coeficientes,z1);
    cout << "El polinomio evaluado con Horner en 1+2i es: ";
    cout << "("<<polinomio.a<<","<<polinomio.b<<")" << '\n';
*/
  ///EVALUAR POLINOMIOS EN NÚMEROS COMPLEJOS
  int grado;
  cout << "GRADO:" << '\n';
  cin >> grado;

  double coeficientes[grado+1];
  for ( k = 0; k <= grado; k++) {
    cout << "a_" << k << "\n";
    cin>>coeficientes[k];
  }
  cout<<"Re(z)=";cin>>z1.a;
  cout<<"\nIm(z)=";cin>>z1.b;

  z2 = cplx_nr( grado, coeficientes, z1 );
  cout << "aproximación: ("<<z2.a<<","<<z2.b<<")\n";

    return 0;
  }
