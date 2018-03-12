#include <iostream>
#include <math.h>
using namespace std;

typedef struct{double a; double b;} numcomplex;
typedef struct{numcomplex array[100];} numcomplex_array;


//Declaración de funciones
long double factorial(long double n);
double cplx_mod(numcomplex z);
numcomplex cplx_conj(numcomplex z);
numcomplex cplx_sum(numcomplex z1, numcomplex z2);
numcomplex cplx_dif(numcomplex z1, numcomplex z2);
numcomplex cplx_prod(numcomplex z1, numcomplex z2);
numcomplex cplx_div(numcomplex z1, numcomplex z2);
numcomplex cplx_pow(numcomplex z1, int n);
numcomplex cplx_raiz(numcomplex z1, double n);
numcomplex cplx_ev_poli(int grado, double coeficientes[], numcomplex z);
numcomplex cplx_horner(int grado, double coeficientes[], numcomplex z);
numcomplex_array raices_nesimas(numcomplex z1, int n);

//funciones trigonométricas
numcomplex cplx_sen(numcomplex z, double tolerancia =0.5*pow(10,-7));



//Variables globales
int k=0;

int main() {
  numcomplex z1, z2;

  z1.a=1;
  z1.b=2;

  z2.a=3;
  z2.b=4;
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
    return 0;
  }

//Definición de funciones
long double factorial(long double n){
  long double factorial=1;
  for(long double i=n;i>1;i--)
  factorial*=i;
  return factorial;
}
double cplx_mod(numcomplex z){
  double modulo=0;
  modulo = sqrt(pow(z.a,2)+pow(z.b,2));
  return modulo;
}
double cplx_fase(numcomplex z){
  if(z.b==0){
    return (z.a>0?(M_PI/2):(-M_PI/2));
  }
  else
    return atan(z.b/z.a);
}
numcomplex cplx_conj(numcomplex z){
  numcomplex zconj;
  zconj = z;
  zconj.b = -zconj.b;
  return zconj;
}
numcomplex cplx_sum(numcomplex z1, numcomplex z2){
  numcomplex z;
  z.a = z1.a+z2.a;
  z.b = z1.b+z2.b;
  return z;
}
numcomplex cplx_dif(numcomplex z1, numcomplex z2){
  numcomplex z;
  z.a = z1.a-z2.a;
  z.b = z1.b-z2.b;
  return z;
}
numcomplex cplx_prod(numcomplex z1, numcomplex z2){
  numcomplex z;
  //(a,b)(c,d)=(ac-bd,ad+bc)
  z.a = z1.a*z2.a - z1.b*z2.b;
  z.b = z1.a*z2.b + z1.b*z2.a;
  return z;

}
numcomplex cplx_div(numcomplex z1, numcomplex z2){
  numcomplex zconj;
  numcomplex z;
  zconj = cplx_conj(z2);

  // z1/z2=(z1*z2')/|z2|
  z = cplx_prod(z1,zconj);
  z.a = z.a/pow(cplx_mod(z2),2);
  z.b = z.b/pow(cplx_mod(z2),2);
  return z;
}


//sobrecarga de funciones para potencias y raíces n-esimas
//cplx_pow calcua la n-ésima potencia entera del número z1
numcomplex cplx_pow(numcomplex z1, int n){
  numcomplex z;
  z.a=pow(cplx_mod(z1),n)*cos(n*cplx_fase(z1));
  z.b=pow(cplx_mod(z1),n)*sin(n*cplx_fase(z1));
  return z;
}
//cplx_raiz calcua la n-ésima potencia fraccionaria del número z1. Devuelve UNA raíz
numcomplex cplx_raiz(numcomplex z1, double n){
  numcomplex z;
    z.a=pow(cplx_mod(z1),n)*cos(n*cplx_fase(z1));
    z.b=pow(cplx_mod(z1),n)*sin(n*cplx_fase(z1));

  return z;
}

//evaluación de polinomios
numcomplex cplx_ev_poli(int grado, double coeficientes[], numcomplex z){
  ///EVALUAR POLINOMIOS EN NÚMEROS COMPLEJOS
  int k=0;
  numcomplex polinomio;
  for(k = 0; k <= grado; k++){
    polinomio.a+=cplx_pow(z,k).a*coeficientes[k];
    polinomio.b+=cplx_pow(z,k).b*coeficientes[k];
  }
  return polinomio;
}
numcomplex cplx_horner(int grado, double coeficientes[], numcomplex z){
  numcomplex polinomio, coef_complejo;

  polinomio.a = coeficientes[grado];
  polinomio.b = 0;

  for(k=grado-1; k >= 0; k--){
    coef_complejo.a = coeficientes[k];
    coef_complejo.b=0;
    polinomio=cplx_sum(coef_complejo,cplx_prod(z,polinomio));
  }
  return polinomio;
}

//Las n potencias n-ésimas del número z. Devuelve un arreglo de tipo numcomplex
numcomplex_array  raices_nesimas(numcomplex z1, int n){
  numcomplex_array arreglo;
  int k=0;
  for(k = 0; k < n; k++){
    arreglo.array[k].a=pow(cplx_mod(z1),1/(double)n)*cos((cplx_fase(z1)+2*k*M_PI)/n);
    arreglo.array[k].b=pow(cplx_mod(z1),1/(double)n)*sin((cplx_fase(z1)+2*k*M_PI)/n);
  }
  return arreglo;
}




//funciones trigonométricas
numcomplex cplx_sen(numcomplex z, double tolerancia){
  //implementa la serie de Taylor con siete cifras por default

  double coeficientes[21], c=0;

  for(k=0; k<=20; k++){
    //La derivada es cíclica:
    if(k%4==0)
      coeficientes[k]=sin(c)/factorial(k);
    if(k%4==1)
      coeficientes[k]=cos(c)/factorial(k);
    if(k%4==2)
      coeficientes[k]=-sin(c)/factorial(k);
    if(k%4==3)
      coeficientes[k]=-cos(c)/factorial(k);
    }

  return cplx_horner(20,coeficientes,z);

}
