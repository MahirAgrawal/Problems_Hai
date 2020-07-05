#include<iostream>
#include<string.h>
#include<conio.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl
//see hackerrank account for char** permutations 
//here char* permutaions i.e. a single word
bool compare_increasing(char *a,char *b)
{
if(*a < *b)
  return true;
else
  return false;
}
bool compare_decreasing(char *a,char *b)
{
if(*a > *b)
  return true;
else
  return false;
}
void swap(char *a,char *b)
{
char temp = *a;
*a = *b;
*b = temp;
}
void reverse(char *start,char *end)
{
while(start++ < end--)//because after comparing start=start+1 so to use
  swap(start-1,end+1);//original start address we do start-1 same logic for
}                     //end in which end becomes end = end-1 after
                      //comparison so we actually pass end+1 so that end is 
		      //maintained at it's original value
char* getting_order(char *s,bool(*compare_function)(char *,char*))
{
int size = strlen(s);
for(auto i = s+size-2;i >= s;i--)
  if(compare_function(i,i+1))
    return i;
return NULL;
}
char* address_to_swap_with(char *s,bool(*compare_function)(char*,char*))
{
int size = strlen(s);
for(auto i = s+size-1;i > s;i--)
  if(compare_function(s,i))
    return i;
}
bool permutation(char *s,bool(*compare_function)(char*,char*))
{
int size = strlen(s);
char *pattern = getting_order(s,compare_function);
if(pattern == NULL)
  return false;
char *greater = address_to_swap_with(pattern,compare_function);
swap(pattern,greater);
reverse(pattern+1,s+size-1);
return true;
}
int main()
{
char str[10];
cout<<"ENTER THE STRING: ";
cin>>str;
cout<<str<<endl;
int count = 1;
while(permutation(str,compare_decreasing))//if 'compare_increasing' fuction
  {cout<<str<<endl;count++;}              //used then next_permutation  
cout<<"THERE ARE "<<count<<" PERMUTATIONS"<<endl;//lexigraphically will
}                                                //occur
