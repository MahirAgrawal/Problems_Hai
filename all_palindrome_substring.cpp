#include<iostream>
#include<string.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl
class palindrome;
struct address{
private:
char *start = NULL;
char *end = NULL;
address()
  {
  this -> start = NULL;
  this -> end = NULL;
  }
void add(char *temp_start,char *temp_end)
  {
  start = temp_start;
  end = temp_end;
  }
bool operator ==(const address& a)
  {
  if((a.start == start) && (end == a.end))
    return true;
  else
    return false;
  }
~address()
  {
  start = NULL;
  end = NULL;
  }
friend class palindrome;
};
class palindrome{
address *ptr = NULL;
int count = 0;
public:
palindrome(int n = 100)
  {
  ptr = new address[2*n];
  }
void add(char *start,char *end)
  {
  if(count == 0)
    {
    ptr[count].add(start,end);
    count++;
    }
  else
    {
    address temp;temp.add(start,end);
    bool flag = true;
    for(int i = 0;i < count;i++)
      {
      if(temp == ptr[i])
        {
	flag = false;
        break;
	}
      }
    if(flag)
      {
      ptr[count].add(start,end);
      count++;
      }
    }
  }
void print()
  {
   for(int i = 0;i < count;i++)
    {
    char *temp_start = ptr[i].start,*temp_end = ptr[i].end;
    while(temp_start <= temp_end)
      {
      cout<<*(temp_start);
      temp_start++;
      }
    cout<<endl;
    }
  }
~palindrome()
  {
  delete []ptr;
  }
};
bool is_palindrome(char *start,char *end)
{
int length = end - start + 1;
for(int i = 0;i < length/2;i++)
  {
  if(start[i] != start[length-1-i])
    return false;
  }
return true;
}
palindrome p;
void palindrome_substring(char *start,char *end)
{
int length = end-start+1;
if(length == 1)
  {
  p.add(start,end);
  return;
  }
for(int i = 0;i < length;i++)
  {
  if(is_palindrome(start,start+i))
    p.add(start,start+i);
  if(i != 0)
    palindrome_substring(start+1,start+i);
  }
}
int main()
{
char str[10];
cout<<"ENTER YOUR STRING: ";
cin>>str;
palindrome_substring(str,str+strlen(str)-1);
p.print();
return 0;
}
