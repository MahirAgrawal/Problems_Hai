#include<iostream>
#include<conio.h>
#include<string.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl
#define condition (s[pos] != s[pos+i])
int count;
void swap(char *a,char *b)
{
char temp = *a;
*a = *b;
*b = temp;
}
void permutation(char *s,int pos = 0)
{
int length = strlen(s+pos);
if(length == 1)
  return;
bool swapped_list[256] = {0};
if(pos == 0)
  {
  cout<<s<<endl;
  count++;
  }
permutation(s,pos+1);
for(int i = 1;i < length;i++)
  {
  bool flag = false;
  if(condition && (!swapped_list[*(s+pos+i)]))
    {
    swapped_list[*(s+pos+i)] = true;
    swap(s+pos,s+pos+i);
    cout<<s<<endl;
    count++;
    flag = true;
    permutation(s,pos+1);
    }
    if(flag)
      swap(s+pos,s+pos+i);
  }
}
int main()
{
char name[30];
cout<<"ENTER YOUR STIRNG: ";
cin>>name;
permutation(name);
cout<<endl<<"THERE ARE "<<count<<" PERMUTATIONS."<<endl;
return 0;
}
