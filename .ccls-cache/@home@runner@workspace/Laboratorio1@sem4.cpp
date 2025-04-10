#include<iostream>
using namespace std;
int main(){
 double arr[]={1,2,3,4,5};
 double* ptr= arr;
  for (int i =0;i<5;i++) {
    *(ptr+i)=*(ptr+i)*10;
  cout<<*(ptr+i)<<endl;  
  }
  for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
  }
  return 0;
}