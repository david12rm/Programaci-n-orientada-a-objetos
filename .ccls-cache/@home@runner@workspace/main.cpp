#include <iostream>
using namespace std;
void regresionLineal(double x[], double y[], double& m, double& b,int n){
  double sumX = 0.0, sumY= 0.0, sumXY = 0.0, sumX2 = 0.0;
  // Calcular las sumas necesarias
for(int i=0 ; i < n ; i++){
    sumX += x[i];
    sumY += y[i];
    sumXY += x[i] * y[i];
    sumX2 += x[i] * x[i];
  // Calcular la pendiente y la ordenada al origen
  m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX*sumX);
    }
}
int main() {
  const int n=5;
double x[n]={1,2,3,4,5};
double y[n]={2.2,2.8,4.5,3.7,5.5};
double m,b;
  regresionLineal(x,y,m,b, n);
  cout<< "La ecuacion de la recta es: y=" << m << "x+" << b << endl;}
