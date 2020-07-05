#include<iostream>
#include<cstdio>
#include<math.h>
#define cin std::cin
#define cout std::cout
#define endl std::endl
void factor(int n = 1)
{
int limit = sqrt(n);
for(int i = 1;i <= limit;i++)
  if(!(n%i))
    cout<<'{'<<i<<','<<n/i<<'}'<<',';
}
int main()
{
int n = 0;
cout<<"ENTER N: ";
cin>>n;
factor(n);
return 0;
}
