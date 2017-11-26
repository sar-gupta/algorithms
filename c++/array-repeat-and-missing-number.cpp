/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    
    /*
    This approach uses extra memory.
    map<int, int> m;
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum += A[i];
        if(m[A[i]])
        {
            m[A[i]]++;
        }
        else
        {
            m[A[i]] = 1;
        }
    }
    int x = 0, max=INT_MIN;
    for(auto& i: m)
    {
        if(i.second>max)
        {
            max = i.second;
            x = i.first;
        }
    }
    vector<int> t;
    t.push_back(x);
    int mis = A.size()*(A.size()+1)/2 - (sum - x);
    t.push_back(mis);
    return t;
    */
    
    long long int sumsq=0, sumarr=0, actualsumarr=0, actualsumsq=0;
    int extra, missing;
    for(long long int i=0;i<A.size();i++)
    {
        sumarr+=(long long int)A[i];
        sumsq+=(long long int)A[i]*A[i];
    }
    long long int n = A.size();
    actualsumarr = n*(n+1)/2;
    actualsumsq = n*(n+1)*(2*n+1)/6;
    /*
    Concept: Two variables, hence we have to make 2 equations and solve them.
    actualsumarr = sumarr - extra + missing
    => (extra - missing) = sumarr - actualsumarr
    actualsumsq = sumsq - (extra^2 - missing^2)
    => (extra-missing)*(extra+missing) = sumsq - actualsumsq
    => extra + missing = (sumsq-actualsumsq)/(sumarr-actualsumarr)
    */
    long long int sumdif=sumarr-actualsumarr, sumsqdif=sumsq-actualsumsq;
    extra = (sumdif + sumsqdif/sumdif)/2;
    missing = extra - sumdif;
    
    vector<int> v {extra, missing};
    return v;
}

int main()
{
  vector<int> A {3,1,2,5,3};
  vector<int> v = repeatedNumber(A);
  cout<<v[0]<<" "<<v[1];
}
