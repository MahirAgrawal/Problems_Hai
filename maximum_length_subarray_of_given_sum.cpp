#include<iostream>
using namespace std;
//MAXIMUM LENGTH OF SUBARRAY HAVING GIVEN SUM
//GIVEN ARRAY WILL CONTAINS "NON NEGATIVE" NUMBERS ONLY
//O(N2)(N SQUARE) APPROACH IS TO RUN TWO LOOP FOR FINDING SUBARRAY
//FOR(EACH I(0 TO N)) RUN INNER LOOP(J(I+1 TO N))
//HERE THE CATCH IS NON NEGATIVE NUMBERS ONLY
//O(N) APPROACH 
//FOR E.G. IF WE FIND GIVEN SUM_ARRAY FROM INDEX 0 T0 3 SUCH THAT SUM_ARRAY == GIVENSUM SO NOTE START INDEX = 0 AND END INDEX = 3 
//NOW BY ADDING 4th INDEX TO SUM_ARRAY, SUM_ARRAY > GIVEN_SUM THEN DO INDEX = 1 AND ALSO SUBTRACT 0TH INDEX ELEMENT FROM SUM_ARRAY TO MAKE 
//SUM_ARRAY < GIVEN_SUM
//BECAUSE IF ADDING NEXT INDEX SUM_ARRAY IF BECOMING LARGER THEN THERE IS NOPOINT OF KEEPING INDEX = 0 TO 3 AS THAT RESULT IS NOTED ALREADY SO WE NOW   CHECK FOR SUBARRAYS FROM INDEX = 1. ALSO WE DON'T HAVE TO START OVER FROM   INDEX = 1 AS WE ALREADY HAVE SUM_ARRAY OF ARRAY FROM 0 TO 3 SO WE ONLY      SUBSTRACT GIVEN_SUM - ARR[0] TO GET SUM FROM INDEX = 1 TO 3 THEN WE ADVANCES TO ADD INDEX = 4,5,... IN SUM_ARRAY
//THIS IS CALLED "SLIDING WINDOW" APPROACH AS WE SLIDE FROM INDEX 0 TO 1 IF SUM_ARRAY > GIVEN_SUM 
//SO IF WE ENCOUNTER A CONSTRAINT THEN WE SHORT OR SLIDE THE ARRAY SPACE    TO MAKE IT SHORT PROBLEM
//SO BY SLIDING FROM INDEX 0 TO 1 ALGORITHM BEHAVES AS IF ARRAY STARTS FROM INDEX = 1 ONLY AND NOT FROM INDEX = 0


//BLOG.GAINLO.CO WEBSITE EXPLANATION (BEST EXPLAINED) ADDED ON HOMESCREEN
//SEE NICK WHITE YOUTUBE VIDEO ON THIS AS WELL ON THIS
int main()
{
int n;
cout<<"ENTER THE NUMBER OF ELEMENTS: ";
cin>>n;
int arr[n];
for(int i = 0;i < n;i++)
  cin>>arr[i];
int sum = 0;
cout<<"ENTER THE SUM: ";
cin>>sum;
int *sum_start = NULL;
int *sum_end = NULL;
int array_sum = 0;
int *start = arr;
int *counter = arr;
while(counter < arr+n)
  {
  array_sum += *counter;
  if(array_sum == sum)
    {
    if((sum_end - sum_start) - (counter - start) < 0)
      {
      //cout<<sum_start-arr<<":"<<sum_end-arr<<endl;
      sum_start = start;
      sum_end = counter;
      }
    }
  while(array_sum > sum)
    {
    array_sum -= *start;
    //cout<<"INDEXIINDE:"<<start-arr<<endl;
    start++;
    }
  /*if(start > counter)
    {
    cout<<"START GOES FAR.."<<*start<<endl;
    cout<<"SUM:"<<array_sum<<endl;
    }*/
  counter++;
  }
if(sum_start == NULL)
  cout<<"NO SUCH ARRAY EXISTS!"<<endl;
else
  cout<<"MAXIMUM LENGHT OF SUBARRAY WHOSE SUM = "<<sum<<" IS "<<sum_end - sum_start + 1<<"FROM INDEX "<<sum_start - arr<<" TO "<<sum_end - arr<<endl;
return 0;
}
