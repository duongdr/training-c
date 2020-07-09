#include<iostream>
using namespace std;
//protype function
int *findMax(int arr[],int n);

int main(){
  int n,i,*p;
  cout<<"Enter number of data values: ";
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)     {
    cout<<"Enter value[i+1]: ";
    cin>>arr[i];
  }

  p=findMax(arr,n);
  cout<<"The max value is:"<<*p;

  return 0;
}

int *findMax(int data[],int n){
  int *max=data;
  int i;
 for(i=1;i<n;i++){
   if(*max<*(max+i))
      *max=*(max+i);
  }
  return max;
}
/* Output */
