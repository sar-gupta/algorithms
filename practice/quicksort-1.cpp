#include<bits/stdc++.h>
using namespace std;

/*
Concept:
Two variables are kept. One is for looping from start to end, the other points to the latest a[i]<pivot that was found.
When some element < pivot is found, then the second variable is incremented and element at first variable is swapped with element at second variable.
*/

int partition(vector<int> &a, int low, int high)
{
  int i=low,j=low-1;
  int part = a[high];
  for(;i<high;i++)
  {
    if(a[i]<=part)
    {
      j++;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  int temp = a[++j];
  a[j] = a[high];
  a[high] = temp;
  return j;
}

void quicksort(vector<int> &a, int low, int high)
{
  if(low<high)
  {
    int p = partition(a,low,high);
    quicksort(a, low, p-1);
    quicksort(a, p+1, high);
  }
}

int main() 
{
  vector<int> a {4,2,5,7,6,1,2,2};
  quicksort(a, 0, a.size()-1);
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<<" ";
  }
}