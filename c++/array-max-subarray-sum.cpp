/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/

// KADANE'S ALGORITHM

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    
    int max_so_far=INT_MIN, max_ending_here=0;
    for(int i=0;i<A.size();i++)
    {
        max_ending_here = max_ending_here+A[i];
        
        max_so_far = max(max_so_far, max_ending_here);
        
        if(max_ending_here<0)
        {
            max_ending_here = 0;
        }
        
    }
    return max_so_far;
}

int main()
{
  vector<int> a {-2,1,-3,4,-1,2,1,-5,4};
  cout<<maxSubArray(a);
}