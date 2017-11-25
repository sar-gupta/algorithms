/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    
    int max_so_far=A[0], curr_max=A[0];
    for(int i=1;i<A.size();i++)
    {
        curr_max = max(curr_max+A[i], A[i]);
        max_so_far = max(max_so_far, curr_max);        
    }
    return max_so_far;
}

int main()
{
  vector<int> a {-2,1,-3,4,-1,2,1,-5,4};
  cout<<maxSubArray(a);
}