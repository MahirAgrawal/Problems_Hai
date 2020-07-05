#include<iostream>
#include"C:/users/lalit/c++_projects/my_time.h"
#define cout std::cout
#define cin std::cin
#define endl std::endl
#define N 1000000
void print_factorial(int n = 0)
{
unsigned short int array[N];
for(unsigned int i = 0;i < N;i++)
  *(array+i) = 1;
unsigned short int *start = array + N - 1;
unsigned short int *end = array + N - 1;
//long unsigned int carry_forward = 0;
long unsigned int temp = 0;
auto temp_end = end;
auto temp_start = start;
timer t;
for(int i = 1;i <= n;i++)
  {
  temp_end = end;temp_start = start;
  while(temp_end >= temp_start)
    {
    temp = *temp_end * i + temp;
    if(temp > 9)
      {
      *temp_end = temp % 10;
      temp /= 10;
      }
    else
      {
      *temp_end = temp;
      temp = 0;
      }
    temp_end--;
  //cout<<"I:"<<i<<"TEMP:"<<temp;
    }
  if(temp != 0)
    {
    while(temp > 9)
      {
      *temp_end = temp % 10;
      temp /= 10;
      temp_end--;
      }
    *temp_end = temp;
    start = temp_end;
    temp = 0;
    }
  else
    start = temp_end + 1;
  }
t.stop();
for(auto address = start;address <= end;address++)
  cout<<*address;
cout<<"\nTHE NUMBER IS "<<end - start + 1<<" long!!"<<endl;
}
int main()
{
unsigned int n;
cout<<"ENTER THE NUMBER FOR IT'S FACTORIAL: ";
cin>>n;
print_factorial(n);
return 0;
}
