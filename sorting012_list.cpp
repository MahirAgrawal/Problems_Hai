#include<iostream>
#include<cstdio>
#define cin std::cin
#define cout std::cout
#define endl std::endl
void swap(int *a,int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
void sorting(int *arr,int n)
{
int *place = arr;
for(int i = 0;i < n;i++)
  {
  if(arr[i] < 1)
    {
    swap(arr+i,place);
    place++;
    }
  }
place = arr+n-1;
for(int i = n-1;i >= 0;i--)
  {
  if(arr[i] > 1)
    {
    swap(arr+i,place);
    place--;
    }
  if(arr[i] == 0)
    break;
  }
}
int main()
{
int arr[10];
for(int i = 0;i < 10;i++)
  cin>>arr[i];
sorting(arr,10);
for(int i = 0;i < 10;i++)
  cout<<arr[i]<<" ";
cout<<endl;
return 0;
}
