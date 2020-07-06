#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define cout std::cout
#define cin std::cin
#define endl std::endl
//CLASS to hold the path and manipulate in my own way required by problem
class array{
char *head = NULL;
int size = 0;
public:
array()
  {
  head = new char[50];
  size = -1;
  }
void push_back(char data)
  {
  size++;
  *(head+size) = data;
  }
void pop_back()
  {
  if(size == -1)
    return;
  size--;
  }
char peek()
  {
  if(size == -1)
    return '\0';
  else
    return *(head+size);
  }
void print()
  {
  for(int i = 0;i <= size;i++)
    cout<<head[i]<<" ";
  cout<<endl;
  }
~array()
  {
  delete []head;
  }
};
//is_valid checks whether the given position is valid for rat to move or not
bool is_valid(void *arr,int i,int j,int n)
{
int *a = (int *)arr;
if(i >= n || j >= n || i < 0 || j < 0)
  return false;
else
  {
  if(*(a+n*i+j) == 0)
    return false;
  else
    return true;
  }
}
array direction;//instance for my array class to help me store the direction
//next_function is the main function which is called to find various safe   paths
bool next_path(void *arr,int i,int j,int n)
{
if(i == n-1 && j == n-1)
  return true;
bool path_right = is_valid(arr,i,j+1,n);
bool path_down = is_valid(arr,i+1,j,n);
if(path_right == false && path_down == false)
  return false;
if(path_right)
  {
  direction.push_back('r');
  if(next_path(arr,i,j+1,n))
    direction.print();
  direction.pop_back();
  }
if(path_down)
  {
  direction.push_back('d');
  if(next_path(arr,i+1,j,n))
    direction.print();
  direction.pop_back();
  }
return false;
}
int main()
{
int n;
cout<<"ENTER YOUR MAZE SIZE: ";
cin>>n;
int path[n][n];
cout<<"ENTER THE PATH:\n";
for(int i = 0;i < n;i++)
  { 
  srand(i);
  for(int j = 0;j < n;j++)
    cin>>path[i][j];
  }
cout<<"THE POSSIBLE WAYS:"<<endl;
next_path(path,0,0,n);
return 0;
}
