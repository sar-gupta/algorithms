#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int dir = 1, rowt = 0, rowb = A.size()-1, colr = A[0].size()-1, coll = 0;
	/*
	0 - left
	1 - right
	2 - up
	3 - down
	*/
	int totalElements = A.size()*A[0].size();
	
	int r=0,c=0;
	
	for (int i=0;i<totalElements;i++)
	{
	    result.push_back(A[r][c]);
	    
	    if (dir == 0 && c>=coll) 
	    {
	        c--;
	    }
	    else if(dir == 1 && c<=colr)
	    {
	        c++;
	    }
	    else if(dir == 2 && r>=rowt)
	    {
	        r--;
	    }
	    else if(dir == 3 && r<=rowb)
	    {
	        r++;
	    }
	    
	    if(r > rowb)
	    {
	        r--;
	        c--;
	        dir = 0;
	        colr--;
	    }
	    else if (r < rowt)
	    {
	        r++;
	        c++;
	        dir = 1;
	        coll++;
	    }
	    else if (c > colr) 
	    {
	        c--;
	        r++;
	        dir = 3;
	        rowt++;
	    }
	    else if (c < coll)
	    {
	        c++;
	        r--;
	        dir = 2;
	        rowb--;
	    }
	    
	    
	}
	
	return result;
}

int main()
{
  vector<vector<int> > A(3);
  A[0].push_back(1);
  A[0].push_back(2);
  A[0].push_back(3);
  A[1].push_back(4);
  A[1].push_back(5);
  A[1].push_back(6);
  A[2].push_back(7);
  A[2].push_back(8);
  A[2].push_back(9);

  for(int i=0;i<A.size();i++)
  {
    cout<<endl;
    for(int j=0;j<A[0].size();j++)
    {
      cout<<A[i][j]<<" ";
    }
  }

  cout<<"\nResult: ";
  vector<int> result = spiralOrder(A);

  for(int i=0;i<result.size();i++)
  {
    cout<<result[i]<<" ";
  }


  
}
