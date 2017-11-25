#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a)
{
  for (int i=1;i<a.size();i++)
  {
    int temp = a[i], j = i-1;
    for(;j>-1 && a[j]>temp;j--)
    {
      a[j+1] = a[j];
    }
    a[++j] = temp;
  }
}

int main()
{
  vector<int> a {4,2,5,7,6,1,2,2};
  insertionSort(a);
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<<" ";
  }
}