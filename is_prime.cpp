#include<cstdio>
#include<math.h>
#include<cstdlib>
//we have to look for factors(if exist) untill sqareroot of given number
//BEACUSE if factors come in pair like for p=6 (1,6) (2,3) (3,2) (6,1)
//HERE 1,2,3,6 are factors but also if for (a,b) a is factor of p=>b is     factor also 
//(a,b) is multiple where a or b compulsory is less or equal to square root of p and p/a = b
//so one number of (a,b) i.e. a must lies in (1,sqrt(p)] and other number of pair can be found by p/a (1 is factor of all so no need to check it)
//so this property is used for finding if prime or not as if 'p' is not     prime then there will be no number in (1,sqrt(p)] as factor because prime has factor 1 and p itself
//for proving that any composite number 'p' has atleast one factor between  (1,sqrt(p)] assume that 
//there is no factors and we get first factor as a:sqrt(p+1) so there will  be 'b' where b:p/a but as b cannot lies in (1,sqrt(p)] so b>= sqrt(p+1) 
//now a*b = p but here sqrt(p+1)*sqrt(p+1) = p+1 which is not possible!!!
//so for any composite number there are factors in pairs (a,b) in which a or b lies in (1,sqrt(p)] and other factor in pair is p/a 
//METHOD 1:
bool is_prime(unsigned int p = 0)
{
unsigned int limit = sqrt(p);
for(unsigned int i = 2;i <= limit;i++)
  if(p % i == 0)
    return false;
return true;
}	
//METHOD 2:
//SIEVE OF ERANTO..
//SEE BEAUTIFUL EXPLANATION OF EDDIE WOO ON YOUTUBE
void sieve_prime(unsigned int n = 0)
{
bool array[n+1];
for(unsigned int i = 2;i < n+1;i++)
  array[i] = true;
for(unsigned int i = 3;i < n+1;i++)
  {
  if(i%2 == 0)
    array[i] = false;
  }
for(unsigned int i = 3;i < n+1;i=i+2)
  {
  for(unsigned int j = i+1;j < n+1;j++)
    {
    if(array[j] && j%i == 0)
      array[j] = false;
    }
  }
for(unsigned int i = 2;i < n+1;i++)
  if(array[i])
    printf("%u,",i);
}
int main()
{
int count =  0;
unsigned int n;
scanf("%u",&n);
for(unsigned int i = 2;i <= n;i++)
  { 
  if(is_prime(i))
    {
    printf("%u,",i);
    count++;
    }
  }
printf("\nPRIME COUNT: %d\n",count);
sieve_prime(n);
}
