#include <iostream>
#include <math.h>
using namespace std;

struct numcomplex{
  double a;
  double b;
} z1, z2;

double cplx_mod(numcomplex z);
numcomplex cplx_conj(numcomplex z);

numcomplex cplx_sum(numcomplex z1, numcomplex z2);
numcomplex cplx_dif(numcomplex z1, numcomplex z2);
numcomplex cplx_prod(numcomplex z1, numcomplex z2);
numcomplex cplx_div(numcomplex z1, numcomplex z2);
numcomplex cplx_pow(numcomplex z1, int n);
numcomplex cplx_raiz(numcomplex z1, double n);
numcomplex raices_nesimas(numcomplex z1, int n);

int main() {
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
  numcomplex *z_raices;
  z_raices = raices_nesimas(z1, 3);
  for(int k=0; k<=3; k++)
    cout << "\n("<<z_raices[k].a<<","<<z_raices[k].b<<")" << '\n';

  return 0;
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
numcomplex cplx_pow(numcomplex z1, int n){
  numcomplex z;
  z.a=pow(cplx_mod(z1),n)*cos(n*cplx_fase(z1));
  z.b=pow(cplx_mod(z1),n)*sin(n*cplx_fase(z1));

  return z;
}

numcomplex cplx_raiz(numcomplex z1, double n){
  numcomplex z;
  //numcomplex array[(int)n];
  //int k=0;
  //for(k = 0; k < n; k++){
    //array[k].a=pow(cplx_mod(z1),n)*cos(n*cplx_fase(z1));
    //array[k].b=pow(cplx_mod(z1),n)*sin(n*cplx_fase(z1));
    z.a=pow(cplx_mod(z1),n)*cos(n*cplx_fase(z1));
    z.b=pow(cplx_mod(z1),n)*sin(n*cplx_fase(z1));
    //cout << "("<<array[k].a<<","<<array[k].b<<")" << '\n';
  //}
  return z;
}




numcomplex * raices_nesimas(numcomplex arr[], numcomplex z1, int n){

  numcomplex array[n];
  int k=0;
  for(k = 0; k < n; k++){
    array[k].a=pow(cplx_mod(z1),1/(double)n)*cos((cplx_fase(z1)+2*k*M_PI)/n);
    array[k].b=pow(cplx_mod(z1),1/(double)n)*sin((cplx_fase(z1)+2*k*M_PI)/n);
  }
  return array;
}
