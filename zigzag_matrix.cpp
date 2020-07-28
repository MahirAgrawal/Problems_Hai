#include<iostream>
#define cout std::cout
#define cin std::cin
#define endl std::endl
bool next(int& i,int& j,int rows,int columns){
  j++;
  i--;
  if(i < 0 || j >= columns){
    j--;
    i++;
    return false;
    }
  else 
    return true;
  }
void get_zigzag(int *arr,int r,int c){
int j = 0,i = 0;
for(i = 0;i < r;i++){
  int i_copy = i;
  do{
    cout<<arr[i_copy*c+j]<<" ";
    }while(next(i_copy,j,r,c));
  j = 0;
  cout<<endl;
  }
i--;
int copy_i,copy_j;
for(j = 1;j < c;j++){
  copy_i = i;
  copy_j = j;
  do{
    cout<<arr[copy_i*c+copy_j]<<" ";
    }while(next(copy_i,copy_j,r,c));
  cout<<endl;
  }
}
void print_matrix(int *a,int r,int c){
  for(int i = 0;i < r;i++){
    for(int j = 0;j < c;j++)
      cout<<a[i*c+j]<<" ";
    cout<<endl;
    }
  }
int main(){
int r = 2,c = 7;
int arr[r*c] = {3,2,48,24,65,82,43,44,42,14,52,37,56,76};
cout<<"MATRIX: "<<endl;
print_matrix(arr,r,c);
cout<<endl;
cout<<"THE ABOVE MATRIX CAN BE PRINTED IN ZIGZAG FORM LIKE BELOW: "<<endl; 
get_zigzag(arr,r,c);
cout<<endl;
r = 5,c = 3;
int array[r*c] = {3,2,48,24,65,82,43,44,42,14,52,37,56,76,67};
cout<<"MATRIX: "<<endl;
print_matrix(array,r,c);
cout<<"\nTHE ABOVE MATRIX CAN BE PRINTED IN ZIGZAG FORM LIKE BELOW: "<<endl; 
get_zigzag(array,r,c);
return 0;
}
