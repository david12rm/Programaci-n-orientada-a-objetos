#include<iostream>
using namespace std;
int main(){
  int numero,*ptr;
  cout<<"Ingrese un numero: " ; cin >> numero;
  ptr=&numero;
  cout<<"La direccion de memoria es: "<<ptr<<endl;
  cout<<"El valor de la variable es: "<<*ptr<<endl;
  if(*ptr%2==0){
    cout<<"El numero es par"<<endl;      
    cout<<"La direccion de memoria es: "<<ptr<<endl;
    cout<<"El valor de la variable es: "<<*ptr<<endl;
  }
  else{
    cout<<"El numero es impar"<<endl;
    cout<<"La direccion de memoria es: "<<ptr<<endl;
    cout<<"El valor de la variable es: "<<*ptr<<endl;
   return 0;
  }    
}