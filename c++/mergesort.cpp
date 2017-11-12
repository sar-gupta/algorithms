#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    // merge two sorted arrays
    vector<int> c;
    int i,j;
    for(i=0,j=0;i<a.size() && j<b.size();) {
        if(a[i]<=b[j]) {
            c.push_back(a[i]);
            i++;
        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
    if(i==a.size()) {
        while(j!=b.size()) {
            c.push_back(b[j++]);
        }
    }
    else if(j==b.size()) {
        while(i!=a.size()) {
            c.push_back(a[i++]);
        }
    }
    return c;
}

vector<int> mergesort(vector<int> a, int start, int end) {
    if (a.size() == 1) {
        return a;
    }
    int mid = (start+end)/2;
    vector<int> first;
    vector<int> second;
    
    for(int i=start;i<mid;i++) {
        first.push_back(a[i]);
    }
    for(int i=mid;i<end;i++) {
        second.push_back(a[i]);
    }
    return merge(mergesort(first, 0, first.size()), mergesort(second, 0, second.size()));
}

int main() {
    vector<int> a {7,1,4,9,3,5,2,5};
    a = mergesort(a, 0, a.size());
    for(auto i = a.begin(); i!=a.end(); i++) {
        cout<<*i;
    }
}