#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;


int main() {
  numcomplex z1, z2;

  z1.a=1;
  z1.b=2;

  z2.a=0;
  z2.b=M_PI;
  //std::cout << "z1= (" <<z1.a<<","<<z1.b<<")\n";
  numcomplex z;
  cout << "modulo: z1" << cplx_mod(z)<< '\n';

  cout<<"Sum";
  z = cplx_sum(z1,z2);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Dif";
  z = cplx_dif(z1,z2);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Prod";
  z = cplx_prod(z1,z2);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Div";
  z = cplx_div(z1,z2);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Conj";
  z = cplx_conj(z1);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Potencia (z1^2):";
  z = cplx_pow( z1, 2);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';
  cout<<"Raiz(z1^1/2):";
  z = cplx_raiz( z1, 0.5);
  cout << "("<<z.a<<","<<z.b<<")" << '\n';

  cout<<"Raices n-esimas(z1, 3):";
  numcomplex_array z_raices;
  z_raices = raices_nesimas(z1, 3);
  for( k=0; k < 2; k++)
  cout << "\n("<<z_raices.array[k].a<<","<<z_raices.array[k].b<<")" << '\n';

  ///EVALUAR POLINOMIOS EN NÚMEROS COMPLEJOS
    int grado;
    cout << "GRADO:" << '\n';
    cin >> grado;

    double coeficientes[grado+1];
    for ( k = 0; k <= grado; k++) {
      cout << "a_" << k << "\n";
      cin>>coeficientes[k];
    }

    numcomplex polinomio=cplx_ev_poli(grado, coeficientes, z1);

    cout << "El polinomio evaluado en 1+2i es: ";
    cout << "("<<polinomio.a<<","<<polinomio.b<<")" << '\n';

    polinomio=cplx_horner(grado, coeficientes,z1);
    cout << "El polinomio evaluado con Horner en 1+2i es: ";
    cout << "("<<polinomio.a<<","<<polinomio.b<<")" << '\n';

    cout << "El seno de 1+2i: ("<<cplx_sen(z1).a<<","<<cplx_sen(z1).b<<")\n";
    cout << "El coseno de 1+2i: ("<<cplx_cos(z1).a<<","<<cplx_cos(z1).b<<")\n";
    cout << "La función exponencial de PIi: ("<<cplx_exp(z2).a<<","<<cplx_exp(z2).b<<")\n";

    return 0;
  }
