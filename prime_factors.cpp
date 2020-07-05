#include<iostream>
#include<math.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl
bool is_prime(int n = 1)
{
if(n <= 1)
  return false;
int limit = sqrt(n);
for(int i = 2;i <= limit;i++)
  if(n%i == 0)
    return false;
return true;
}
void prime_factor(int n = 1)
{
int limit = sqrt(n);
for(int i = 1;i <= limit;i++)
  if(n%i == 0)
    {
    if(is_prime(i))
      cout<<i<<' ';
    if(is_prime(n/i))
      cout<<(n/i)<<' ';
    }
cout<<endl;
}
int main()
{
int n = 0;
cout<<"ENTER THE NUMBER FOR IT'S PRIME FACTORS: ";
cin>>n;
prime_factor(n);
return 0;
}
