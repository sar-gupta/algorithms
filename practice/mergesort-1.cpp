#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
  // This function merges two sorted arrays
  vector<int> c;
  int i,j;
  for(i=0,j=0;i<a.size() && j<b.size();)
  {
    if(a[i] < b[j])
    {
      c.push_back(a[i]);
      i++;
    }
    else
    {
      c.push_back(b[j]);
      j++;
    }
  }
  while(i<a.size())
  {
    c.push_back(a[i++]);
  }
  while(j<b.size())
  {
    c.push_back(b[j++]);
  }
  return c;
}

vector<int> mergesort(vector<int> a, int l, int r)
{
  if(a.size() == 1)
  {
    return a;
  }
  int mid = (l+r)/2, i=0;
  vector<int> b,c;
  for(i=l;i<mid;i++)
  {
    b.push_back(a[i]);
  }
  for(i=mid;i<r;i++)
  {
    c.push_back(a[i]);
  }
  b = mergesort(b,0,b.size());
  c = mergesort(c,0,c.size());
  a = merge(b,c);
  return a;
  // return merge(mergesort(b,0,b.size()), mergesort(c,0,c.size()));
}

int main() 
{
  vector<int> a {4,2,5,7,6,1,2,2};
  a = mergesort(a, 0, a.size());
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<<" ";
  }
}