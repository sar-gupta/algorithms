/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
*/

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])

#include<bits/stdc++.h>
using namespace std;
int coverPoints(vector<int> &X, vector<int> &Y) {
    
    int steps = 0;
    for(int i=1;i<X.size();i++)
    {
        int xdif = abs(X[i]-X[i-1]);
        int ydif = abs(Y[i]-Y[i-1]);
        steps = steps + min(xdif,ydif) + abs(xdif-ydif);
        
    }
    return steps;  
}

int main()
{
  vector<int> x {0,1,1}, y {0,1,2};
  cout<<coverPoints(x,y);
}
